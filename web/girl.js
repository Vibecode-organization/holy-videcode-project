/* Оригинальная талисман-девочка в стиле аниме 90-х: большие глаза, наушники, ахоге.
   girl(options) возвращает SVG-строку. Цвета можно менять. */
(function () {
  let uid = 0;
  const INK = '#2b2350';

  function eye(id, cx, side) {
    const s = side; // -1 левый, 1 правый
    const lash = s < 0
      ? `M${cx - 29} 196 C${cx - 19} 172 ${cx + 17} 168 ${cx + 29} 188`
      : `M${cx - 29} 188 C${cx - 17} 168 ${cx + 19} 172 ${cx + 29} 196`;
    const flick = s < 0 ? `M${cx - 27} 194 l-11 -7` : `M${cx + 27} 194 l11 -7`;
    return `
    <g class="g-eye">
      <ellipse cx="${cx}" cy="208" rx="23" ry="30" fill="#fff" stroke="${INK}" stroke-width="2"/>
      <g clip-path="url(#${id}c${s})">
        <g class="g-iris">
          <ellipse cx="${cx + 1}" cy="214" rx="19" ry="26" fill="url(#${id}i)"/>
          <ellipse cx="${cx + 1}" cy="217" rx="9" ry="13" fill="#1a1238"/>
          <ellipse cx="${cx - 7}" cy="203" rx="7" ry="9.5" fill="#fff"/>
          <circle cx="${cx + 8}" cy="227" r="3.5" fill="#fff"/>
          <path d="M${cx - 13} 233 q14 8 28 0" stroke="#fff" stroke-width="2" fill="none" opacity=".7"/>
        </g>
      </g>
      <path d="${lash}" stroke="${INK}" stroke-width="7" fill="none" stroke-linecap="round"/>
      <path d="${flick}" stroke="${INK}" stroke-width="5" stroke-linecap="round"/>
      <path d="M${cx - 14} 240 q14 5 28 0" stroke="${INK}" stroke-width="2" fill="none" stroke-linecap="round"/>
    </g>`;
  }

  window.girl = function (o = {}) {
    const id = 'hvg' + (++uid);
    const c = Object.assign({
      hair: '#ff9ccf', hairDark: '#d65a9c',
      eye: '#6b5bff', eyeLight: '#a6ecff',
      jacket: '#7c6cff', jacketDark: '#5546d6',
      phones: '#ffd34d'
    }, o);

    return `
<svg class="girl" viewBox="0 0 400 500" xmlns="http://www.w3.org/2000/svg" aria-hidden="true">
  <defs>
    <linearGradient id="${id}h" x1="0" y1="0" x2="0" y2="1">
      <stop offset="0" stop-color="${c.hair}"/><stop offset="1" stop-color="${c.hairDark}"/>
    </linearGradient>
    <linearGradient id="${id}i" x1="0" y1="0" x2="0" y2="1">
      <stop offset="0" stop-color="#241a4a"/><stop offset=".45" stop-color="${c.eye}"/><stop offset="1" stop-color="${c.eyeLight}"/>
    </linearGradient>
    <clipPath id="${id}c-1"><ellipse cx="165" cy="208" rx="23" ry="30"/></clipPath>
    <clipPath id="${id}c1"><ellipse cx="235" cy="208" rx="23" ry="30"/></clipPath>
  </defs>
  <g class="g-bob">
    <path class="g-hairback" fill="url(#${id}h)" stroke="${INK}" stroke-width="3"
      d="M122 150 C88 230 98 340 70 440 L150 420 L200 350 L250 420 L330 440 C302 340 312 230 278 150 C268 80 240 48 200 48 C160 48 132 80 122 150Z"/>

    <path fill="${c.jacketDark}" stroke="${INK}" stroke-width="3" d="M80 502 C86 405 135 352 200 344 C265 352 314 405 320 502Z"/>
    <path fill="${c.jacket}" d="M100 502 C106 418 146 366 200 356 C254 366 294 418 300 502Z"/>
    <path fill="#ffd9c7" stroke="${INK}" stroke-width="3" d="M180 268 L220 268 L222 345 C210 356 190 356 178 345Z"/>
    <path fill="#f2b3a1" d="M181 286 C192 298 208 298 219 286 L220 306 C208 316 192 316 180 306Z"/>
    <path fill="#fff" stroke="${INK}" stroke-width="3" stroke-linejoin="round" d="M166 346 L200 400 L234 346 L218 340 L200 372 L182 340Z"/>
    <path class="g-pin" fill="${c.phones}" stroke="${INK}" stroke-width="3" stroke-linejoin="round"
      d="M262 410 l7 14 15 2 -11 10 3 15 -14 -7 -14 7 3 -15 -11 -10 15 -2z"/>

    <path fill="#ffe4d8" stroke="${INK}" stroke-width="3"
      d="M130 165 C128 225 160 280 200 302 C240 280 272 225 270 165 C270 112 240 86 200 86 C160 86 130 112 130 165Z"/>

    <g class="g-blush">
      <ellipse cx="148" cy="250" rx="18" ry="9" fill="#ff8fb1" opacity=".45"/>
      <ellipse cx="252" cy="250" rx="18" ry="9" fill="#ff8fb1" opacity=".45"/>
      <path stroke="#ff6f9c" stroke-width="2" stroke-linecap="round" d="M139 254 l6 -8 M147 254 l6 -8 M155 254 l6 -8 M243 254 l6 -8 M251 254 l6 -8 M259 254 l6 -8"/>
    </g>

    ${eye(id, 165, -1)}
    ${eye(id, 235, 1)}

    <path d="M142 166 q22 -10 42 0 M216 166 q20 -10 42 0" stroke="${INK}" stroke-width="3" fill="none" stroke-linecap="round"/>
    <path d="M203 238 l-4 7 h5" stroke="#d98f7c" stroke-width="2.5" fill="none" stroke-linecap="round" stroke-linejoin="round"/>
    <path class="g-mouth" d="M189 266 Q200 276 211 266" stroke="${INK}" stroke-width="3" fill="#ff7a9a" stroke-linecap="round" stroke-linejoin="round"/>

    <path fill="url(#${id}h)" stroke="${INK}" stroke-width="3" stroke-linejoin="round"
      d="M132 150 C116 210 124 270 108 318 C134 292 146 236 150 176Z M268 150 C284 210 276 270 292 318 C266 292 254 236 250 176Z"/>
    <path fill="url(#${id}h)" stroke="${INK}" stroke-width="3" stroke-linejoin="round"
      d="M122 178 C116 98 152 60 200 58 C248 60 284 98 278 178 L264 140 L256 172 L240 122 L226 164 L208 112 L192 162 L172 118 L158 170 L144 136Z"/>
    <path d="M158 84 q42 -20 84 0" stroke="#fff" stroke-width="6" opacity=".55" fill="none" stroke-linecap="round"/>
    <path class="g-ahoge" fill="url(#${id}h)" stroke="${INK}" stroke-width="3" stroke-linejoin="round"
      d="M196 62 C184 24 214 10 232 22 C212 25 205 40 206 62Z"/>

    <path d="M124 182 C114 58 286 58 276 182" stroke="${INK}" stroke-width="18" fill="none" stroke-linecap="round"/>
    <path d="M124 182 C114 58 286 58 276 182" stroke="${c.phones}" stroke-width="11" fill="none" stroke-linecap="round"/>
    <rect x="106" y="158" width="32" height="60" rx="15" fill="${c.phones}" stroke="${INK}" stroke-width="3"/>
    <rect x="262" y="158" width="32" height="60" rx="15" fill="${c.phones}" stroke="${INK}" stroke-width="3"/>
    <circle cx="122" cy="188" r="7" fill="#ff7ab8" stroke="${INK}" stroke-width="2"/>
    <circle cx="278" cy="188" r="7" fill="#ff7ab8" stroke="${INK}" stroke-width="2"/>
  </g>
</svg>`;
  };
})();
