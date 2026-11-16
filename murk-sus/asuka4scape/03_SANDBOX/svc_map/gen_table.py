#!/usr/bin/env python3
# build the service table for REPORT.md
import json, os, re, sys

W = '/home/femboychik/work/svc_map'
app = json.load(open(f'{W}/app_allowed_big.json'))
best = json.load(open(f'{W}/machlookup_best.json'))
svc = json.load(open(f'{W}/svc_plists.json'))
fs = json.load(open(f'{W}/fs_sizes.json'))
ents = json.load(open(f'{W}/exe_ents.json'))
dead = set(json.load(open(f'{W}/dead_split.json'))['dead'])

AUDITED = {
    'com.apple.mobile.installd': 'да (AK)',
    'com.apple.containermanagerd': 'да',
    'com.apple.containermanagerd.system': 'да',
    'com.apple.MobileFileIntegrity': 'да (amfid)',
    'com.apple.sharing.sharesheet': 'проверен, пусто',
    'com.apple.sharingd.nsxpc': 'проверен, пусто',
    'com.apple.coremedia.mediaparserd.formatreader.xpc': 'проверен, пусто',
    'com.apple.coremedia.mediaparserd.jsonparser.xpc': 'проверен, пусто',
    'com.apple.coremedia.mediaparserd.mutablemovie.xpc': 'проверен, пусто',
}

# (regex on service|exe, tag, score, note)
RULES = [
    ('mediaanalysisd', 'media', 9, 'разбор фото/видео: URL+UTI на входе, ML-пайплайн, отдаёт теги/эмбеддинги'),
    ('maild$|mobilemail', 'file', 9, 'MIME/EML, вложения из URL, autosave-данные, индексация'),
    ('passd', 'file', 9, 'pkpass (zip+JSON+подпись), платёжные токены, CBOR'),
    ('managedappdistributiond', 'install', 9, 'каталог манифестов, установка/обновление, SINF, decrypter'),
    ('Search.framework/searchd|spotlight', 'file', 8, 'индексатор: метаданные, импортеры, fileprovider-URL'),
    ('CacheDelete|/deleted', 'path', 8, 'удаление по путям от клиента, purge-токены, контейнеры'),
    ('nsurlsessiond', 'net', 8, 'фоновые загрузки: URL → путь назначения в чужом контейнере'),
    ('ThumbnailsAgent', 'file', 8, 'превью произвольного файла через QL-генераторы'),
    ('imagent', 'file', 8, 'сообщения/вложения, разбор MIME'),
    ('fontservicesd|FontProviderLoader', 'file', 7, 'разбор шрифтов (OTF/TTC), рендер глифов'),
    ('iconservices', 'file', 6, 'иконки приложений: рендер из бандла'),
    ('assetsd|photos', 'media', 7, 'фотобиблиотека: ассеты, производные, cacheDelete'),
    ('fileprovider|FileCoordination|FileProvider', 'path', 7, 'провайдеры файлов, координация путей между контейнерами'),
    ('linkd', 'file', 6, 'транскрипты/шорткаты, разбор данных'),
    ('shazamd', 'media', 6, 'аудиофингерпринт по буферу'),
    ('storekitd|itunesstored|appstored', 'net', 6, 'JWS/квитанции, каталог, установка'),
    ('attributionkitd|adprivacyd|promotedcontentd', 'net', 5, 'атрибуция, парсинг ответов'),
    ('mobilegestalt', 'info', 5, 'свойства устройства'),
    ('lsd', 'path', 6, 'LaunchServices: регистрация, URL, БД приложений'),
    ('cfprefsd', 'prefs', 4, 'preferences'),
    ('mobile.keybagd|ak.auth|securityd|CoreAuthentication', 'sec', 7, 'ключи/токены, Keychain'),
    ('pasteboard|pasted', 'ipc', 6, 'буфер обмена, произвольные данные между приложениями'),
    ('dasd|duetactivityscheduler', 'sched', 3, 'планировщик'),
    ('runningboard|frontboard|backboard|SpringBoard|usernotifications', 'ui', 2, 'UI/процессы'),
    ('locationd', 'priv', 6, 'геолокация'),
    ('commcenter|CoreTelephony', 'priv', 5, 'телефония/SIM'),
    ('wifid|mobilewifi|networkserviceproxy|configd|mDNSResponder|networkd', 'net', 5, 'сеть'),
    ('bluetoothd|nearbyd|accessoryd|iapd|dockaccessoryd', 'hw', 4, 'аксессуары/BT'),
    ('voice|speech|dictation|assistant', 'media', 4, 'речь/аудио'),
    ('mediaremoted|audiomxd|mediaplaybackd|videocodecd|medialibraryd', 'media', 5, 'медиа-пайплайн'),
    ('symptomsd|diagnosticd|analyticsd|logd|osanalytics', 'log', 2, 'диагностика'),
    ('mobileassetd|axassetsd|vsassetd', 'asset', 5, 'MobileAsset: скачивание и распаковка ассетов'),
    ('Audi|accessib|VoiceOver|assistivetouch|AX', 'ui', 1, 'доступность'),
    ('siri|Siri|assistant', 'media', 3, 'Siri'),
    ('homed|homekit|HomeKit', 'priv', 4, 'HomeKit'),
    ('contactsd|Contacts', 'priv', 3, 'контакты'),
    ('healthd|Health', 'priv', 3, 'здоровье'),
    ('ScreenTime|progressd|ClassKit', 'priv', 3, 'ScreenTime/учебные данные'),
    ('gamed|gamecenter|GameCenter', 'net', 3, 'Game Center'),
    ('safarifetcherd|WebKit|webinspector', 'net', 5, 'загрузка/рендер веба'),
    ('print|Print', 'file', 4, 'печать, разбор документов'),
    ('ckd|cloudd|CloudKit|bird|itunescloudd', 'net', 5, 'облачная синхронизация'),
]

DEFAULT_TAGS = [
    (r'install|appstore|stored|store', 'install', 5),
    (r'media|audio|video|photo|image|png|jpeg|codec', 'media', 5),
    (r'file|asset|document|container|disk|volume', 'file', 4),
    (r'net|url|http|dns|proxy|socket|wifi|network', 'net', 4),
    (r'key|auth|security|crypt|token|credential', 'sec', 3),
    (r'parse|decode|reader|loader|import|convert', 'parse', 5),
]


def score(n, exe):
    s = n + ' ' + exe
    for pat, tag, sc, note in RULES:
        if re.search(pat, s, re.I):
            return tag, sc, note
    for pat, tag, sc in DEFAULT_TAGS:
        if re.search(pat, s, re.I):
            return tag, sc, ''
    return 'sys', 2, ''


def ent_brief(exe):
    e = (ents.get(exe) or {}).get('ent') or {}
    if not e:
        return '—'
    parts = [f"{len(e)}k"]
    ml = e.get('com.apple.security.exception.mach-lookup.global-name')
    if isinstance(ml, str) and ml.startswith('LIST:'):
        parts.append('mach+' + str(ml.count(',') + 1))
    if any(k.startswith('com.apple.private.security.storage') or 'MobileContainerManager' in k for k in e):
        parts.append('cont')
    if any('tcc' in k for k in e):
        parts.append('tcc')
    if any('allowedSPI' in k for k in e):
        parts.append('spi')
    if any('fileprovider' in k for k in e):
        parts.append('fp')
    return ' '.join(parts)


rows = []
for n in sorted(app):
    e = (svc.get(n) or [{}])[0]
    exe = (e.get('exe') or '').lstrip('/')
    sz = fs.get(exe, 0) if exe else 0
    tag, sc, note = score(n, exe)
    rows.append(dict(name=n, exe=exe or '—', sz=sz, ent=ent_brief(exe) if exe else '—',
                     aud=AUDITED.get(n, ''), tag=tag, score=sc, note=note,
                     dead=n in dead))

rows.sort(key=lambda r: (-r['score'], -r['sz'], r['name']))
out = []
out.append('| # | сервис | бинарь | размер | ent | аудирован | ценность |')
out.append('|---|---|---|---|---|---|---|')
for i, r in enumerate(rows, 1):
    sz = f"{r['sz']/1024:.0f}K" if r['sz'] < 1024 * 1024 else f"{r['sz']/1048576:.1f}M"
    nm = r['name']
    dg = ' †' if r['dead'] else ''
    out.append(f"| {i} | `{nm}`{dg} | `{r['exe']}` | {sz if r['sz'] else '—'} | {r['ent']} | {r['aud'] or '—'} | {r['tag']} {r['score']} |")
open(f'{W}/table.md', 'w').write('\n'.join(out) + '\n')
json.dump(rows, open(f'{W}/rows.json', 'w'), indent=0)
print('rows', len(rows), 'dead', sum(1 for r in rows if r['dead']))
print('top20:', [(r['name'], r['tag'], r['score']) for r in rows[:20]])
