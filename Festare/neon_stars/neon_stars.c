#define _WIN32_WINNT 0x0601
#include <windows.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "winmm.lib")

#define MAX_STARS      8000
#define MAX_ALIVE      3000
#define START_STARS    600
#define SPAWN_INTERVAL 40
#define SPACE_BURST    20
#define WIN_W          640
#define WIN_H          480
#define PI             3.14159265358979323846
#define MAX_THREADS    32

#define ATTRACT_RADIUS 120.0f
#define ATTRACT_FORCE  0.30f
#define STICK_DIST      4.0f

#define PHYS_DAMPING   0.965f
#define STICK_LERP     0.22f
#define BOUND_BOUNCE   0.85f

typedef struct {
    float x, y;
    float vx, vy;
    float r;
    float rTarget;
    float alpha;
    int   stuck;
    int   alive;
    uint32_t color;
} Star;

static Star          g_stars[MAX_STARS];
static volatile LONG g_count = 0;
static float         g_mx = 0, g_my = 0;
static int           g_winW = WIN_W;
static int           g_winH = WIN_H;

static LARGE_INTEGER g_freq;
static LARGE_INTEGER g_lastTime;
static int           g_fps = 0;
static int           g_frames = 0;
static double        g_fpsAccum = 0.0;

static double g_lastSpawnTime = 0.0;

static HBITMAP   g_dib     = NULL;
static uint32_t *g_pixels  = NULL;
static HDC       g_memDC   = NULL;
static HBITMAP   g_oldBmp  = NULL;
static int       g_bufW    = 0, g_bufH = 0;

static int           g_nThreads = 4;
static HANDLE        g_threads[MAX_THREADS];
static HANDLE        g_evStart[MAX_THREADS];
static HANDLE        g_evDone[MAX_THREADS];
static volatile LONG g_stopFlag = 0;
static int           g_phase = 0;

typedef struct { int y0, y1; } Range;
static Range g_drawRange[MAX_THREADS];
static Range g_physRange[MAX_THREADS];

static float frand(float a, float b) {
    return a + (b - a) * (rand() / (float)RAND_MAX);
}

static float lerp(float a, float b, float t) {
    return a + (b - a) * t;
}

static void ensure_dib(HDC hdc) {
    if (g_dib && g_bufW == g_winW && g_bufH == g_winH) return;
    if (g_memDC) {
        SelectObject(g_memDC, g_oldBmp);
        DeleteObject(g_dib);
        DeleteDC(g_memDC);
    }
    BITMAPINFO bi = {0};
    bi.bmiHeader.biSize        = sizeof(BITMAPINFOHEADER);
    bi.bmiHeader.biWidth       = g_winW;
    bi.bmiHeader.biHeight      = -g_winH;
    bi.bmiHeader.biPlanes      = 1;
    bi.bmiHeader.biBitCount    = 32;
    bi.bmiHeader.biCompression = BI_RGB;

    void *bits = NULL;
    g_dib = CreateDIBSection(hdc, &bi, DIB_RGB_COLORS, &bits, NULL, 0);
    g_pixels = (uint32_t*)bits;
    g_memDC = CreateCompatibleDC(hdc);
    g_oldBmp = (HBITMAP)SelectObject(g_memDC, g_dib);
    g_bufW = g_winW;
    g_bufH = g_winH;

    for (int t = 0; t < g_nThreads; t++) {
        g_drawRange[t].y0 = (g_winH * t) / g_nThreads;
        g_drawRange[t].y1 = (g_winH * (t + 1)) / g_nThreads;
        g_physRange[t].y0 = g_drawRange[t].y0;
        g_physRange[t].y1 = g_drawRange[t].y1;
    }
}

static int spawn_star(void) {
    for (int i = 0; i < MAX_STARS; i++) {
        if (!g_stars[i].alive) {
            Star *s = &g_stars[i];
            s->x = frand(10, g_winW - 10);
            s->y = frand(10, g_winH - 10);
            s->vx = frand(-0.6f, 0.6f);
            s->vy = frand(-0.6f, 0.6f);
            s->r  = 0.0f;
            s->rTarget = frand(3.0f, 4.5f);
            s->alpha = 0.0f;
            s->stuck = 0;
            s->alive = 1;
            static const uint32_t palette[] = {
                0x00FFFF, 0xFF00FF, 0x00FF80, 0xB400FF,
                0xFFFF00, 0xFF5050, 0x78C8FF, 0xFFB400
            };
            s->color = palette[rand() % 8];
            return 1;
        }
    }
    return 0;
}

static int count_alive(void) {
    int n = 0;
    for (int i = 0; i < MAX_STARS; i++)
        if (g_stars[i].alive) n++;
    return n;
}

static void try_auto_spawn(void) {
    LARGE_INTEGER now;
    QueryPerformanceCounter(&now);
    double t = (double)now.QuadPart / (double)g_freq.QuadPart;
    if (t - g_lastSpawnTime < SPAWN_INTERVAL / 1000.0) return;
    if (count_alive() >= MAX_ALIVE) return;
    if (spawn_star()) g_lastSpawnTime = t;
}

static inline void blend_add(uint32_t *px, int x, int y, uint32_t c, int a) {
    if (x < 0 || y < 0 || x >= g_winW || y >= g_winH) return;
    if (a <= 0) return;
    uint32_t dst = px[y * g_winW + x];
    int r = (dst & 0xFF)         + (((c >> 16) & 0xFF) * a / 255);
    int g = ((dst >> 8) & 0xFF)  + (((c >> 8)  & 0xFF) * a / 255);
    int b = ((dst >> 16) & 0xFF) + (( c        & 0xFF) * a / 255);
    if (r > 255) r = 255;
    if (g > 255) g = 255;
    if (b > 255) b = 255;
    px[y * g_winW + x] = (r) | (g << 8) | (b << 16);
}

static void draw_star_px(uint32_t *px, Star *s) {
    int cx = (int)s->x;
    int cy = (int)s->y;
    int rad = (int)(s->r * s->alpha);
    if (rad < 1) rad = 1;

    int alphaMul = (int)(s->alpha * 255);
    if (alphaMul <= 0) return;

    blend_add(px, cx, cy, s->color, alphaMul);
    for (int dy = -rad; dy <= rad; dy++) {
        for (int dx = -rad; dx <= rad; dx++) {
            if (dx == 0 && dy == 0) continue;
            int d2 = dx*dx + dy*dy;
            if (d2 > rad*rad) continue;
            int a = (180 - d2 * 40) * alphaMul / 255;
            if (a < 30 * alphaMul / 255) a = 30 * alphaMul / 255;
            blend_add(px, cx + dx, cy + dy, s->color, a);
        }
    }
    blend_add(px, cx + rad + 1, cy, s->color, 60 * alphaMul / 255);
    blend_add(px, cx - rad - 1, cy, s->color, 60 * alphaMul / 255);
    blend_add(px, cx, cy + rad + 1, s->color, 60 * alphaMul / 255);
    blend_add(px, cx, cy - rad - 1, s->color, 60 * alphaMul / 255);
}

static void update_fps(void) {
    LARGE_INTEGER now;
    QueryPerformanceCounter(&now);
    double dt = (double)(now.QuadPart - g_lastTime.QuadPart) / (double)g_freq.QuadPart;
    g_lastTime = now;
    g_frames++;
    g_fpsAccum += dt;
    if (g_fpsAccum >= 0.25) {
        g_fps = (int)(g_frames / g_fpsAccum);
        g_frames = 0;
        g_fpsAccum = 0.0;
    }
}

static DWORD WINAPI worker_thread(LPVOID param) {
    int idx = (int)(intptr_t)param;
    for (;;) {
        WaitForSingleObject(g_evStart[idx], INFINITE);
        if (g_stopFlag) break;

        if (g_phase == 0) {
            int y0 = g_physRange[idx].y0;
            int y1 = g_physRange[idx].y1;
            int localStuck = 0;

            int totalStuck = 0;
            for (int i = 0; i < MAX_STARS; i++)
                if (g_stars[i].alive && g_stars[i].stuck) totalStuck++;

            int stuckIndex = 0;
            for (int i = 0; i < MAX_STARS; i++) {
                Star *s = &g_stars[i];
                if (!s->alive) continue;

                if (s->alpha < 1.0f) s->alpha += 0.05f;
                if (s->alpha > 1.0f) s->alpha = 1.0f;
                s->r = lerp(s->r, s->rTarget, 0.15f);

                int inBand = ((int)s->y >= y0 && (int)s->y < y1);

                if (s->stuck) {
                    if (inBand) {
                        float ang = (2 * PI * stuckIndex) / (totalStuck > 0 ? totalStuck : 1);
                        float orbit = 16.0f;
                        float tx = g_mx + cosf(ang) * orbit;
                        float ty = g_my + sinf(ang) * orbit;
                        s->x = lerp(s->x, tx, STICK_LERP);
                        s->y = lerp(s->y, ty, STICK_LERP);
                        s->vx = s->vy = 0;
                    }
                    stuckIndex++;
                    continue;
                }

                if (!inBand) continue;

                float dx = g_mx - s->x;
                float dy = g_my - s->y;
                float dist = sqrtf(dx*dx + dy*dy);

                if (dist < ATTRACT_RADIUS && dist > 0.01f) {
                    float t = 1.0f - dist / ATTRACT_RADIUS;
                    float force = ATTRACT_FORCE * t * t;
                    s->vx += (dx / dist) * force;
                    s->vy += (dy / dist) * force;
                }

                if (dist < STICK_DIST + s->r) {
                    s->stuck = 1;
                    localStuck++;
                    continue;
                }

                s->x += s->vx;
                s->y += s->vy;
                s->vx *= PHYS_DAMPING;
                s->vy *= PHYS_DAMPING;

                if (s->x < s->r)          { s->x = s->r;          s->vx = -s->vx * BOUND_BOUNCE; }
                if (s->x > g_winW - s->r) { s->x = g_winW - s->r; s->vx = -s->vx * BOUND_BOUNCE; }
                if (s->y < s->r)          { s->y = s->r;          s->vy = -s->vy * BOUND_BOUNCE; }
                if (s->y > g_winH - s->r) { s->y = g_winH - s->r; s->vy = -s->vy * BOUND_BOUNCE; }
            }
            if (localStuck) InterlockedAdd(&g_count, localStuck);
        } else {
            int y0 = g_drawRange[idx].y0;
            int y1 = g_drawRange[idx].y1;

            uint32_t bgColor = (10) | (10 << 8) | (20 << 16);
            for (int y = y0; y < y1; y++) {
                uint32_t *row = &g_pixels[y * g_winW];
                for (int x = 0; x < g_winW; x++) row[x] = bgColor;
            }

            for (int i = 0; i < MAX_STARS; i++) {
                Star *s = &g_stars[i];
                if (!s->alive) continue;
                int cy = (int)s->y;
                if (cy < y0 || cy >= y1) continue;
                draw_star_px(g_pixels, s);
            }
        }
        SetEvent(g_evDone[idx]);
    }
    return 0;
}

static void run_parallel_phase(int phase) {
    g_phase = phase;
    for (int i = 0; i < g_nThreads; i++) ResetEvent(g_evDone[i]);
    for (int i = 0; i < g_nThreads; i++) SetEvent(g_evStart[i]);
    for (int i = 0; i < g_nThreads; i++) WaitForSingleObject(g_evDone[i], INFINITE);
}

static void on_click(int x, int y) {
    (void)x; (void)y;
    for (int i = 0; i < MAX_STARS; i++) {
        Star *s = &g_stars[i];
        if (s->alive && s->stuck) {
            float ang = frand(0, 2 * PI);
            float spd = frand(6, 14);
            s->vx = cosf(ang) * spd;
            s->vy = sinf(ang) * spd;
            s->stuck = 0;
        }
    }
}

static LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
    switch (msg) {
    case WM_SIZE:
        if (wp == SIZE_MINIMIZED) return 0;
        {
            RECT rc;
            GetClientRect(hwnd, &rc);
            int nw = rc.right - rc.left;
            int nh = rc.bottom - rc.top;
            if (nw < 1) nw = 1;
            if (nh < 1) nh = 1;
            g_winW = nw;
            g_winH = nh;
        }
        for (int i = 0; i < MAX_STARS; i++) {
            Star *s = &g_stars[i];
            if (!s->alive) continue;
            if (s->x < s->r)          s->x = s->r;
            if (s->x > g_winW - s->r) s->x = (float)(g_winW - s->r);
            if (s->y < s->r)          s->y = s->r;
            if (s->y > g_winH - s->r) s->y = (float)(g_winH - s->r);
        }
        return 0;

    case WM_LBUTTONDOWN:
        g_mx = (float)LOWORD(lp); g_my = (float)HIWORD(lp);
        on_click((int)g_mx, (int)g_my);
        return 0;
    case WM_MOUSEMOVE:
        g_mx = (float)LOWORD(lp); g_my = (float)HIWORD(lp);
        return 0;
    case WM_KEYDOWN:
        if (wp == VK_ESCAPE) PostQuitMessage(0);
        if (wp == VK_SPACE) {
            for (int k = 0; k < SPACE_BURST; k++) {
                if (count_alive() >= MAX_STARS) break;
                spawn_star();
            }
        }
        return 0;
    case WM_DESTROY:
        if (g_memDC) {
            SelectObject(g_memDC, g_oldBmp);
            DeleteObject(g_dib);
            DeleteDC(g_memDC);
        }
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd, msg, wp, lp);
}

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrev, LPSTR cmd, int show) {
    (void)hPrev; (void)cmd;
    srand((unsigned)GetTickCount());
    QueryPerformanceFrequency(&g_freq);
    QueryPerformanceCounter(&g_lastTime);
    SetProcessDPIAware();
    timeBeginPeriod(1);

    SYSTEM_INFO si;
    GetSystemInfo(&si);
    g_nThreads = (int)si.dwNumberOfProcessors;
    if (g_nThreads < 1) g_nThreads = 1;
    if (g_nThreads > MAX_THREADS) g_nThreads = MAX_THREADS;

    for (int i = 0; i < g_nThreads; i++) {
        g_evStart[i] = CreateEvent(NULL, FALSE, FALSE, NULL);
        g_evDone[i]  = CreateEvent(NULL, FALSE, FALSE, NULL);
    }
    for (int i = 0; i < g_nThreads; i++) {
        g_threads[i] = CreateThread(NULL, 0, worker_thread, (LPVOID)(intptr_t)i, 0, NULL);
    }

    WNDCLASSA wc = {0};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInst;
    wc.hCursor = LoadCursor(NULL, IDC_CROSS);
    wc.hbrBackground = CreateSolidBrush(RGB(10, 10, 20));
    wc.lpszClassName = "NeonStarsClass";
    RegisterClassA(&wc);

    RECT wr = {0, 0, WIN_W, WIN_H};
    AdjustWindowRect(&wr, WS_OVERLAPPEDWINDOW, FALSE);
    HWND hwnd = CreateWindowA("NeonStarsClass", "Neon Stars",
        WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
        wr.right - wr.left, wr.bottom - wr.top,
        NULL, NULL, hInst, NULL);

    for (int i = 0; i < START_STARS; i++) spawn_star();
    ShowWindow(hwnd, show);

    {
        LARGE_INTEGER now;
        QueryPerformanceCounter(&now);
        g_lastSpawnTime = (double)now.QuadPart / (double)g_freq.QuadPart;
    }

    MSG msg;
    while (1) {
        while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
            if (msg.message == WM_QUIT) {
                g_stopFlag = 1;
                for (int i = 0; i < g_nThreads; i++) SetEvent(g_evStart[i]);
                WaitForMultipleObjects(g_nThreads, g_threads, TRUE, 1000);
                return 0;
            }
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        if (IsIconic(hwnd)) {
            Sleep(10);
            continue;
        }

        try_auto_spawn();
        update_fps();

        HDC hdc = GetDC(hwnd);
        ensure_dib(hdc);

        run_parallel_phase(0);
        run_parallel_phase(1);

        SetBkMode(g_memDC, TRANSPARENT);
        char buf[64];
        sprintf(buf, "Collected: %d", (int)g_count);
        SetTextColor(g_memDC, RGB(200, 200, 255));
        TextOutA(g_memDC, 12, 12, buf, (int)strlen(buf));

        char fpsBuf[32];
        sprintf(fpsBuf, "FPS: %d", g_fps);
        SetTextColor(g_memDC, RGB(0, 255, 200));
        SIZE fpsSize;
        GetTextExtentPoint32A(g_memDC, fpsBuf, (int)strlen(fpsBuf), &fpsSize);
        TextOutA(g_memDC, g_winW - fpsSize.cx - 12, 12, fpsBuf, (int)strlen(fpsBuf));

        BitBlt(hdc, 0, 0, g_winW, g_winH, g_memDC, 0, 0, SRCCOPY);
        ReleaseDC(hwnd, hdc);

        SwitchToThread();
    }
}