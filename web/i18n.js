/* Переводы сайта. Языки: en, es, zh, ru, ja, ko.
   Ключи с суффиксом _html вставляются как разметка (только наш собственный текст). */
(function () {
  'use strict';

  const TOKEN_URL = 'https://github.com/settings/tokens/new?scopes=public_repo&description=Holy%20VibeCode';
  const tokenLink = (text) => `<a href="${TOKEN_URL}" target="_blank" rel="noopener">${text}</a>`;

  const LANGS = [
    ['en', 'English'], ['es', 'Español'], ['zh', '中文'],
    ['ru', 'Русский'], ['ja', '日本語'], ['ko', '한국어']
  ];

  const D = {};

  D.ru = {
    'nav.home': 'Главная', 'nav.projects': 'Проекты', 'nav.support': 'Поддержка', 'nav.join': 'Вступить', 'nav.lang': 'Язык',
    ribbon: '★ HOLY VIBECODE ★ ホーリー・バイブコード ★ ЛЮБАЯ ПЛАТФОРМА ★ ЛЮБОЙ УРОВЕНЬ ★ ВАЙБКОДЕРЫ ВСЕГО МИРА ★ ',
    'meta.desc': 'Holy VibeCode — открытая коллекция проектов вайбкодеров со всего мира.',
    'hero.lead': 'Открытая коллекция проектов вайбкодеров со всего мира. Любая платформа, любой стек, любой уровень — от первого «Hello, World!» до полноценного продукта.',
    'hero.cta1': 'Смотреть проекты', 'hero.cta2': 'Поддержать авторов',
    'stat.authors': 'авторов', 'stat.projects': 'проектов', 'stat.support': 'в поддержке',
    'girl.aria': 'Талисман Holy VibeCode',
    'f1.t': 'Для всех', 'f1.d': 'Новички и профи, дизайнеры, музыканты, художники — каждый, кто создаёт что-то вместе с ИИ.',
    'f2.t': 'Без ограничений', 'f2.d': 'Веб, мобильные приложения, игры, боты, AI-агенты, утилиты и эксперименты.',
    'f3.t': 'Поддержка авторов', 'f3.d': 'Участники сами указывают реквизиты, а вы можете поддержать любимый проект напрямую.',
    'proj.title': 'Проекты', 'proj.sub': 'Список собирается автоматически из папок репозитория.',
    'sup.title': 'Поддержка',
    'sup.sub': 'Здесь участники репозитория публикуют свои реквизиты. Каждый может добавить и изменить только свои — сайт проверяет ник через GitHub.',
    'sup.add': 'Добавить свои реквизиты',
    'login.title': 'Вход через GitHub',
    'login.desc_html': 'Сайт работает без сервера, поэтому для входа нужен личный токен GitHub. Он хранится только в этой вкладке браузера и отправляется только на <code>api.github.com</code>.',
    'login.s1_html': `Откройте ${tokenLink('создание токена')} (тип <b>classic</b>, галочка <code>public_repo</code> уже стоит).`,
    'login.s2_html': 'Нажмите <b>Generate token</b> и скопируйте его.',
    'login.s3': 'Вставьте токен ниже.',
    'login.btn': 'Войти',
    'form.who': 'Вы редактируете только свои реквизиты', 'form.logout': 'Выйти',
    'form.name': 'Отображаемое имя', 'form.name.ph': 'Как вас называть',
    'form.msg': 'Сообщение для поддерживающих', 'form.msg.ph': 'Например: на что пойдут донаты',
    'form.methods': 'Способы оплаты', 'form.optional': 'Все поля по желанию',
    'form.warn': 'Репозиторий публичный: всё, что вы укажете, увидят все. Не добавляйте то, что не хотите показывать.',
    'form.delete': 'Удалить мои реквизиты', 'form.save': 'Сохранить',
    'join.title': 'Как вступить',
    'j1.t': 'Напишите в личку', 'j1.note': 'Название проекта, что он делает и ссылку на код или демо.',
    'j2.t': 'Создайте папки', 'j2.d': 'Папка с вашим ником на GitHub, внутри — папка для каждого проекта.',
    'j2.note_html': 'Если в папке проекта есть <code>index.html</code>, на сайте появится кнопка «Демо».',
    'j3.t': 'Выложите релиз', 'j3.d_html': 'Один проект — один релиз — один архив <code>НазваниеПроекта_Автор.zip</code> со всеми версиями внутри.',
    'j3.btn': 'Открыть релизы',
    footer: 'Сделано с ♥ вайбкодерами для вайбкодеров',
    copied: 'Скопировано!', copyFail: 'Не удалось скопировать', maxMethods: 'Максимум {n} способов',
    phrases: ['Добро пожаловать, вайбкодер!', 'Покажи свой проект миру ★', 'Любая платформа подходит!', 'Не бойся начать с Hello, World!', 'Поддержи авторов во вкладке «Поддержка» ♥', 'Вайбкодинг — это магия ✧', 'Кто-то сейчас пишет промпт мечты…'],
    'projCount.one': '{n} проект', 'projCount.few': '{n} проекта', 'projCount.many': '{n} проектов', 'projCount.other': '{n} проекта',
    emptyProjects: 'Проектов пока нет — стань первым!',
    emptySupT: 'Пока никто не добавил реквизиты', emptySupD: 'Участники репозитория могут добавить свои — кнопка выше.',
    errRate: 'GitHub временно ограничил запросы. Попробуйте через несколько минут.', errLoad: 'Не удалось загрузить данные с GitHub.',
    customLabel: 'Свой способ', otherLabel: 'Другое', customLabelPh: 'Название (например: Сбер, DonationAlerts)', customValuePh: 'Реквизиты или ссылка',
    checking: 'Проверяю…',
    noRights: '@{login}, у вас нет прав на изменение репозитория. Добавлять реквизиты могут только участники — напишите владельцу.',
    badToken: 'Токен не подошёл. Проверьте, что скопировали его полностью.', error: 'Ошибка: {m}',
    loadingMine: 'Загружаю ваши реквизиты…', loadFail: 'Не удалось загрузить: {m}',
    fixFields: 'Исправьте поля, отмеченные красным.', needOne: 'Добавьте хотя бы один способ оплаты.',
    saving: 'Сохраняю…', saved: 'Сохранено! На сайте для всех обновится примерно через минуту.',
    conflict: 'Файл изменился, обновите страницу и попробуйте снова.', saveErr: 'Ошибка сохранения: {m}',
    confirmDelete: 'Удалить ваши реквизиты с сайта?', deleting: 'Удаляю…', deleted: 'Реквизиты удалены.', delErr: 'Ошибка удаления: {m}',
    copyBtn: 'Копировать', code: 'Код', demo: 'Демо', remove: 'Удалить', close: 'Закрыть',
    needLabel: 'Укажите название способа', looksWrong: 'Похоже на ошибку: {hint}',
    'hint.trc20': 'Адрес в сети TRON, начинается с T', 'hint.tron': 'Адрес TRON, начинается с T',
    'hint.monobank': 'Номер карты или ссылка на банку send.monobank.ua', 'hint.tbank': 'Номер карты, телефон (СБП) или ссылка',
    'hint.ton': 'Адрес TON (48 символов)', 'hint.btc': 'Адрес Bitcoin', 'hint.eth': 'Адрес Ethereum, начинается с 0x',
    'hint.paypal': 'Ссылка paypal.me или e-mail', 'hint.boosty': 'Ссылка https://boosty.to/...', 'hint.kofi': 'Ссылка https://ko-fi.com/...',
    'hint.custom': 'Любые реквизиты: название и значение'
  };

  D.en = {
    'nav.home': 'Home', 'nav.projects': 'Projects', 'nav.support': 'Support', 'nav.join': 'Join', 'nav.lang': 'Language',
    ribbon: '★ HOLY VIBECODE ★ ホーリー・バイブコード ★ ANY PLATFORM ★ ANY LEVEL ★ VIBECODERS WORLDWIDE ★ ',
    'meta.desc': 'Holy VibeCode is an open collection of projects by vibecoders from all over the world.',
    'hero.lead': 'An open collection of projects by vibecoders from all over the world. Any platform, any stack, any level — from a first “Hello, World!” to a full-fledged product.',
    'hero.cta1': 'Browse projects', 'hero.cta2': 'Support the authors',
    'stat.authors': 'authors', 'stat.projects': 'projects', 'stat.support': 'accept support',
    'girl.aria': 'Holy VibeCode mascot',
    'f1.t': 'For everyone', 'f1.d': 'Beginners and pros, designers, musicians, artists — anyone who creates things together with AI.',
    'f2.t': 'No limits', 'f2.d': 'Web, mobile apps, games, bots, AI agents, tools and experiments.',
    'f3.t': 'Support the authors', 'f3.d': 'Members list their own payment details, so you can support a project you love directly.',
    'proj.title': 'Projects', 'proj.sub': 'The list is built automatically from the repository folders.',
    'sup.title': 'Support',
    'sup.sub': 'Repository members publish their payment details here. Everyone can add and edit only their own — the site checks your username via GitHub.',
    'sup.add': 'Add your details',
    'login.title': 'Sign in with GitHub',
    'login.desc_html': 'The site has no server, so signing in requires a personal GitHub token. It is kept only in this browser tab and sent only to <code>api.github.com</code>.',
    'login.s1_html': `Open ${tokenLink('token creation')} (type <b>classic</b>, the <code>public_repo</code> box is already checked).`,
    'login.s2_html': 'Click <b>Generate token</b> and copy it.',
    'login.s3': 'Paste the token below.',
    'login.btn': 'Sign in',
    'form.who': 'You can only edit your own details', 'form.logout': 'Sign out',
    'form.name': 'Display name', 'form.name.ph': 'What should we call you',
    'form.msg': 'Message for supporters', 'form.msg.ph': 'E.g. what donations will be spent on',
    'form.methods': 'Payment methods', 'form.optional': 'All fields are optional',
    'form.warn': 'The repository is public: everything you enter will be visible to everyone. Don’t add anything you don’t want to share.',
    'form.delete': 'Delete my details', 'form.save': 'Save',
    'join.title': 'How to join',
    'j1.t': 'Send a DM', 'j1.note': 'The project name, what it does and a link to the code or demo.',
    'j2.t': 'Create folders', 'j2.d': 'A folder with your GitHub username, and inside it a folder for each project.',
    'j2.note_html': 'If a project folder has an <code>index.html</code>, a “Demo” button appears on the site.',
    'j3.t': 'Publish a release', 'j3.d_html': 'One project — one release — one archive <code>ProjectName_Author.zip</code> with all versions inside.',
    'j3.btn': 'Open releases',
    footer: 'Made with ♥ by vibecoders, for vibecoders',
    copied: 'Copied!', copyFail: 'Couldn’t copy', maxMethods: 'Maximum {n} methods',
    phrases: ['Welcome, vibecoder!', 'Show your project to the world ★', 'Any platform works!', 'Don’t be afraid to start with Hello, World!', 'Support the authors in the “Support” tab ♥', 'Vibecoding is magic ✧', 'Someone is writing their dream prompt right now…'],
    'projCount.one': '{n} project', 'projCount.other': '{n} projects',
    emptyProjects: 'No projects yet — be the first!',
    emptySupT: 'Nobody has added payment details yet', emptySupD: 'Repository members can add theirs with the button above.',
    errRate: 'GitHub has temporarily limited requests. Try again in a few minutes.', errLoad: 'Couldn’t load data from GitHub.',
    customLabel: 'Custom method', otherLabel: 'Other', customLabelPh: 'Name (e.g. Wise, DonationAlerts)', customValuePh: 'Details or link',
    checking: 'Checking…',
    noRights: '@{login}, you don’t have permission to modify the repository. Only members can add payment details — message the owner.',
    badToken: 'The token didn’t work. Make sure you copied all of it.', error: 'Error: {m}',
    loadingMine: 'Loading your details…', loadFail: 'Couldn’t load: {m}',
    fixFields: 'Fix the fields marked in red.', needOne: 'Add at least one payment method.',
    saving: 'Saving…', saved: 'Saved! It will update on the site for everyone in about a minute.',
    conflict: 'The file has changed. Reload the page and try again.', saveErr: 'Save error: {m}',
    confirmDelete: 'Remove your details from the site?', deleting: 'Deleting…', deleted: 'Details removed.', delErr: 'Delete error: {m}',
    copyBtn: 'Copy', code: 'Code', demo: 'Demo', remove: 'Remove', close: 'Close',
    needLabel: 'Enter the method name', looksWrong: 'Looks wrong: {hint}',
    'hint.trc20': 'TRON network address, starts with T', 'hint.tron': 'TRON address, starts with T',
    'hint.monobank': 'Card number or send.monobank.ua jar link', 'hint.tbank': 'Card number, phone (SBP) or link',
    'hint.ton': 'TON address (48 characters)', 'hint.btc': 'Bitcoin address', 'hint.eth': 'Ethereum address, starts with 0x',
    'hint.paypal': 'paypal.me link or e-mail', 'hint.boosty': 'Link https://boosty.to/...', 'hint.kofi': 'Link https://ko-fi.com/...',
    'hint.custom': 'Any details: name and value'
  };

  D.es = {
    'nav.home': 'Inicio', 'nav.projects': 'Proyectos', 'nav.support': 'Apoyo', 'nav.join': 'Unirse', 'nav.lang': 'Idioma',
    ribbon: '★ HOLY VIBECODE ★ ホーリー・バイブコード ★ CUALQUIER PLATAFORMA ★ CUALQUIER NIVEL ★ VIBECODERS DE TODO EL MUNDO ★ ',
    'meta.desc': 'Holy VibeCode es una colección abierta de proyectos de vibecoders de todo el mundo.',
    'hero.lead': 'Una colección abierta de proyectos de vibecoders de todo el mundo. Cualquier plataforma, cualquier stack, cualquier nivel: desde el primer «Hello, World!» hasta un producto completo.',
    'hero.cta1': 'Ver proyectos', 'hero.cta2': 'Apoyar a los autores',
    'stat.authors': 'autores', 'stat.projects': 'proyectos', 'stat.support': 'aceptan apoyo',
    'girl.aria': 'Mascota de Holy VibeCode',
    'f1.t': 'Para todos', 'f1.d': 'Principiantes y profesionales, diseñadores, músicos, artistas: cualquiera que cree algo junto con la IA.',
    'f2.t': 'Sin límites', 'f2.d': 'Web, apps móviles, juegos, bots, agentes de IA, utilidades y experimentos.',
    'f3.t': 'Apoya a los autores', 'f3.d': 'Los participantes indican sus propios datos de pago y puedes apoyar directamente tu proyecto favorito.',
    'proj.title': 'Proyectos', 'proj.sub': 'La lista se genera automáticamente a partir de las carpetas del repositorio.',
    'sup.title': 'Apoyo',
    'sup.sub': 'Aquí los participantes del repositorio publican sus datos de pago. Cada uno solo puede añadir y editar los suyos: el sitio verifica tu usuario a través de GitHub.',
    'sup.add': 'Añadir mis datos',
    'login.title': 'Iniciar sesión con GitHub',
    'login.desc_html': 'El sitio funciona sin servidor, así que para iniciar sesión necesitas un token personal de GitHub. Solo se guarda en esta pestaña del navegador y solo se envía a <code>api.github.com</code>.',
    'login.s1_html': `Abre la ${tokenLink('creación de token')} (tipo <b>classic</b>, la casilla <code>public_repo</code> ya está marcada).`,
    'login.s2_html': 'Pulsa <b>Generate token</b> y cópialo.',
    'login.s3': 'Pega el token abajo.',
    'login.btn': 'Entrar',
    'form.who': 'Solo puedes editar tus propios datos', 'form.logout': 'Salir',
    'form.name': 'Nombre visible', 'form.name.ph': 'Cómo quieres que te llamen',
    'form.msg': 'Mensaje para quienes te apoyan', 'form.msg.ph': 'Por ejemplo: en qué se usarán las donaciones',
    'form.methods': 'Métodos de pago', 'form.optional': 'Todos los campos son opcionales',
    'form.warn': 'El repositorio es público: todo lo que indiques será visible para todos. No añadas nada que no quieras mostrar.',
    'form.delete': 'Eliminar mis datos', 'form.save': 'Guardar',
    'join.title': 'Cómo unirse',
    'j1.t': 'Escríbeme por privado', 'j1.note': 'El nombre del proyecto, qué hace y un enlace al código o a la demo.',
    'j2.t': 'Crea las carpetas', 'j2.d': 'Una carpeta con tu usuario de GitHub y, dentro, una carpeta para cada proyecto.',
    'j2.note_html': 'Si la carpeta del proyecto tiene un <code>index.html</code>, aparecerá el botón «Demo» en el sitio.',
    'j3.t': 'Publica una release', 'j3.d_html': 'Un proyecto, una release, un archivo <code>NombreProyecto_Autor.zip</code> con todas las versiones dentro.',
    'j3.btn': 'Abrir releases',
    footer: 'Hecho con ♥ por vibecoders, para vibecoders',
    copied: '¡Copiado!', copyFail: 'No se pudo copiar', maxMethods: 'Máximo {n} métodos',
    phrases: ['¡Bienvenido, vibecoder!', 'Muestra tu proyecto al mundo ★', '¡Cualquier plataforma sirve!', 'No tengas miedo de empezar con Hello, World!', 'Apoya a los autores en la pestaña «Apoyo» ♥', 'El vibecoding es magia ✧', 'Alguien está escribiendo ahora el prompt de sus sueños…'],
    'projCount.one': '{n} proyecto', 'projCount.other': '{n} proyectos',
    emptyProjects: 'Aún no hay proyectos. ¡Sé el primero!',
    emptySupT: 'Nadie ha añadido datos de pago todavía', emptySupD: 'Los participantes del repositorio pueden añadir los suyos con el botón de arriba.',
    errRate: 'GitHub ha limitado temporalmente las solicitudes. Inténtalo de nuevo en unos minutos.', errLoad: 'No se pudieron cargar los datos de GitHub.',
    customLabel: 'Método propio', otherLabel: 'Otro', customLabelPh: 'Nombre (por ejemplo: Bizum, Wise)', customValuePh: 'Datos o enlace',
    checking: 'Comprobando…',
    noRights: '@{login}, no tienes permiso para modificar el repositorio. Solo los participantes pueden añadir datos de pago: escribe al propietario.',
    badToken: 'El token no funcionó. Comprueba que lo copiaste completo.', error: 'Error: {m}',
    loadingMine: 'Cargando tus datos…', loadFail: 'No se pudo cargar: {m}',
    fixFields: 'Corrige los campos marcados en rojo.', needOne: 'Añade al menos un método de pago.',
    saving: 'Guardando…', saved: '¡Guardado! Se actualizará en el sitio para todos en aproximadamente un minuto.',
    conflict: 'El archivo ha cambiado. Recarga la página e inténtalo de nuevo.', saveErr: 'Error al guardar: {m}',
    confirmDelete: '¿Eliminar tus datos del sitio?', deleting: 'Eliminando…', deleted: 'Datos eliminados.', delErr: 'Error al eliminar: {m}',
    copyBtn: 'Copiar', code: 'Código', demo: 'Demo', remove: 'Eliminar', close: 'Cerrar',
    needLabel: 'Indica el nombre del método', looksWrong: 'Parece un error: {hint}',
    'hint.trc20': 'Dirección de la red TRON, empieza por T', 'hint.tron': 'Dirección TRON, empieza por T',
    'hint.monobank': 'Número de tarjeta o enlace de hucha send.monobank.ua', 'hint.tbank': 'Número de tarjeta, teléfono (SBP) o enlace',
    'hint.ton': 'Dirección TON (48 caracteres)', 'hint.btc': 'Dirección de Bitcoin', 'hint.eth': 'Dirección de Ethereum, empieza por 0x',
    'hint.paypal': 'Enlace paypal.me o e-mail', 'hint.boosty': 'Enlace https://boosty.to/...', 'hint.kofi': 'Enlace https://ko-fi.com/...',
    'hint.custom': 'Cualquier dato: nombre y valor'
  };

  D.zh = {
    'nav.home': '首页', 'nav.projects': '项目', 'nav.support': '支持', 'nav.join': '加入', 'nav.lang': '语言',
    ribbon: '★ HOLY VIBECODE ★ ホーリー・バイブコード ★ 任何平台 ★ 任何水平 ★ 全世界的氛围编程者 ★ ',
    'meta.desc': 'Holy VibeCode —— 来自世界各地氛围编程者的开放项目合集。',
    'hero.lead': '来自世界各地氛围编程者的开放项目合集。任何平台、任何技术栈、任何水平——从第一个“Hello, World!”到完整的产品。',
    'hero.cta1': '浏览项目', 'hero.cta2': '支持作者',
    'stat.authors': '作者', 'stat.projects': '项目', 'stat.support': '接受支持',
    'girl.aria': 'Holy VibeCode 吉祥物',
    'f1.t': '面向所有人', 'f1.d': '新手和专家、设计师、音乐人、艺术家——所有与 AI 一起创作的人。',
    'f2.t': '没有限制', 'f2.d': '网站、移动应用、游戏、机器人、AI 智能体、工具和各种实验。',
    'f3.t': '支持作者', 'f3.d': '成员自行填写收款方式，你可以直接支持喜欢的项目。',
    'proj.title': '项目', 'proj.sub': '列表根据仓库中的文件夹自动生成。',
    'sup.title': '支持',
    'sup.sub': '仓库成员在这里发布自己的收款方式。每个人只能添加和修改自己的信息——网站会通过 GitHub 验证你的用户名。',
    'sup.add': '添加我的收款方式',
    'login.title': '使用 GitHub 登录',
    'login.desc_html': '本网站没有服务器，因此登录需要 GitHub 个人令牌。令牌只保存在当前浏览器标签页中，并且只会发送到 <code>api.github.com</code>。',
    'login.s1_html': `打开${tokenLink('令牌创建页面')}（类型选 <b>classic</b>，<code>public_repo</code> 已勾选）。`,
    'login.s2_html': '点击 <b>Generate token</b> 并复制令牌。',
    'login.s3': '将令牌粘贴到下方。',
    'login.btn': '登录',
    'form.who': '你只能编辑自己的信息', 'form.logout': '退出',
    'form.name': '显示名称', 'form.name.ph': '你希望别人怎么称呼你',
    'form.msg': '给支持者的留言', 'form.msg.ph': '例如：捐款将用于什么',
    'form.methods': '收款方式', 'form.optional': '所有字段均为选填',
    'form.warn': '仓库是公开的：你填写的所有内容所有人都能看到。请不要添加不想公开的信息。',
    'form.delete': '删除我的信息', 'form.save': '保存',
    'join.title': '如何加入',
    'j1.t': '私信我', 'j1.note': '项目名称、项目用途，以及代码或演示链接。',
    'j2.t': '创建文件夹', 'j2.d': '以你的 GitHub 用户名创建一个文件夹，并在其中为每个项目各建一个文件夹。',
    'j2.note_html': '如果项目文件夹中有 <code>index.html</code>，网站上会出现“演示”按钮。',
    'j3.t': '发布版本', 'j3.d_html': '一个项目——一个 Release——一个压缩包：把所有版本放进 <code>项目名_作者.zip</code>。',
    'j3.btn': '打开 Releases',
    footer: '由氛围编程者用 ♥ 为氛围编程者打造',
    copied: '已复制！', copyFail: '复制失败', maxMethods: '最多 {n} 种方式',
    phrases: ['欢迎你，氛围编程者！', '向世界展示你的项目 ★', '任何平台都可以！', '别怕从 Hello, World! 开始', '在“支持”页面支持作者吧 ♥', '氛围编程就是魔法 ✧', '有人正在写梦想中的提示词……'],
    'projCount.other': '{n} 个项目',
    emptyProjects: '还没有项目——成为第一个吧！',
    emptySupT: '还没有人添加收款方式', emptySupD: '仓库成员可以通过上方按钮添加自己的信息。',
    errRate: 'GitHub 暂时限制了请求，请几分钟后再试。', errLoad: '无法从 GitHub 加载数据。',
    customLabel: '自定义方式', otherLabel: '其他', customLabelPh: '名称（例如：支付宝、微信）', customValuePh: '收款信息或链接',
    checking: '正在验证……',
    noRights: '@{login}，你没有修改该仓库的权限。只有成员才能添加收款方式——请联系仓库所有者。',
    badToken: '令牌无效，请确认已完整复制。', error: '错误：{m}',
    loadingMine: '正在加载你的信息……', loadFail: '加载失败：{m}',
    fixFields: '请修正标红的字段。', needOne: '请至少添加一种收款方式。',
    saving: '正在保存……', saved: '已保存！大约一分钟后所有人都能在网站上看到更新。',
    conflict: '文件已被修改，请刷新页面后重试。', saveErr: '保存失败：{m}',
    confirmDelete: '要从网站上删除你的信息吗？', deleting: '正在删除……', deleted: '信息已删除。', delErr: '删除失败：{m}',
    copyBtn: '复制', code: '代码', demo: '演示', remove: '删除', close: '关闭',
    needLabel: '请填写方式名称', looksWrong: '似乎有误：{hint}',
    'hint.trc20': 'TRON 网络地址，以 T 开头', 'hint.tron': 'TRON 地址，以 T 开头',
    'hint.monobank': '卡号或 send.monobank.ua 存钱罐链接', 'hint.tbank': '卡号、手机号（SBP）或链接',
    'hint.ton': 'TON 地址（48 个字符）', 'hint.btc': '比特币地址', 'hint.eth': '以太坊地址，以 0x 开头',
    'hint.paypal': 'paypal.me 链接或电子邮箱', 'hint.boosty': '链接 https://boosty.to/...', 'hint.kofi': '链接 https://ko-fi.com/...',
    'hint.custom': '任意收款信息：名称和内容'
  };

  D.ja = {
    'nav.home': 'ホーム', 'nav.projects': 'プロジェクト', 'nav.support': 'サポート', 'nav.join': '参加', 'nav.lang': '言語',
    ribbon: '★ HOLY VIBECODE ★ ホーリー・バイブコード ★ どんなプラットフォームでも ★ どんなレベルでも ★ 世界中のバイブコーダー ★ ',
    'meta.desc': 'Holy VibeCode — 世界中のバイブコーダーによるプロジェクトのオープンなコレクション。',
    'hero.lead': '世界中のバイブコーダーによるプロジェクトのオープンなコレクション。どんなプラットフォームでも、どんな技術スタックでも、どんなレベルでも——はじめての「Hello, World!」から本格的なプロダクトまで。',
    'hero.cta1': 'プロジェクトを見る', 'hero.cta2': '作者を応援する',
    'stat.authors': '作者', 'stat.projects': 'プロジェクト', 'stat.support': '支援受付中',
    'girl.aria': 'Holy VibeCode のマスコット',
    'f1.t': 'すべての人に', 'f1.d': '初心者もプロも、デザイナー、ミュージシャン、アーティストも——AI と一緒に何かを作るすべての人へ。',
    'f2.t': '制限なし', 'f2.d': 'Web、モバイルアプリ、ゲーム、ボット、AI エージェント、ツール、実験的な作品まで。',
    'f3.t': '作者を応援', 'f3.d': 'メンバーが自分の支払い方法を掲載しているので、好きなプロジェクトを直接応援できます。',
    'proj.title': 'プロジェクト', 'proj.sub': 'リストはリポジトリのフォルダから自動で作成されます。',
    'sup.title': 'サポート',
    'sup.sub': 'リポジトリのメンバーがここに支払い方法を掲載しています。追加・編集できるのは自分の情報だけです——サイトが GitHub でユーザー名を確認します。',
    'sup.add': '自分の支払い方法を追加',
    'login.title': 'GitHub でログイン',
    'login.desc_html': 'このサイトにはサーバーがないため、ログインには GitHub の個人トークンが必要です。トークンはこのブラウザタブにのみ保存され、<code>api.github.com</code> にのみ送信されます。',
    'login.s1_html': `${tokenLink('トークン作成ページ')}を開きます（種類は <b>classic</b>、<code>public_repo</code> にはすでにチェックが入っています）。`,
    'login.s2_html': '<b>Generate token</b> を押してコピーします。',
    'login.s3': '下にトークンを貼り付けます。',
    'login.btn': 'ログイン',
    'form.who': '編集できるのは自分の情報だけです', 'form.logout': 'ログアウト',
    'form.name': '表示名', 'form.name.ph': '呼ばれたい名前',
    'form.msg': '応援してくれる人へのメッセージ', 'form.msg.ph': '例：寄付の使い道',
    'form.methods': '支払い方法', 'form.optional': 'すべて任意です',
    'form.warn': 'リポジトリは公開されています。入力した内容は誰でも見られるので、公開したくない情報は追加しないでください。',
    'form.delete': '自分の情報を削除', 'form.save': '保存',
    'join.title': '参加方法',
    'j1.t': 'DM を送る', 'j1.note': 'プロジェクト名、内容、コードまたはデモへのリンクを送ってください。',
    'j2.t': 'フォルダを作る', 'j2.d': 'GitHub のユーザー名でフォルダを作り、その中にプロジェクトごとのフォルダを作ります。',
    'j2.note_html': 'プロジェクトのフォルダに <code>index.html</code> があると、サイトに「デモ」ボタンが表示されます。',
    'j3.t': 'リリースを公開', 'j3.d_html': '1 プロジェクト＝1 リリース＝1 アーカイブ。すべてのバージョンを <code>プロジェクト名_作者.zip</code> にまとめます。',
    'j3.btn': 'リリースを開く',
    footer: 'バイブコーダーによる、バイブコーダーのためのサイト ♥',
    copied: 'コピーしました！', copyFail: 'コピーできませんでした', maxMethods: '最大 {n} 件までです',
    phrases: ['ようこそ、バイブコーダーさん！', 'あなたのプロジェクトを世界に見せよう ★', 'どんなプラットフォームでも OK！', 'Hello, World! から始めても大丈夫', '「サポート」タブで作者を応援してね ♥', 'バイブコーディングは魔法 ✧', '今まさに誰かが夢のプロンプトを書いてる…'],
    'projCount.other': '{n} 件のプロジェクト',
    emptyProjects: 'まだプロジェクトがありません——最初の一人になろう！',
    emptySupT: 'まだ誰も支払い方法を追加していません', emptySupD: 'リポジトリのメンバーは上のボタンから追加できます。',
    errRate: 'GitHub のリクエスト制限に達しました。数分後にもう一度お試しください。', errLoad: 'GitHub からデータを読み込めませんでした。',
    customLabel: 'その他の方法', otherLabel: 'その他', customLabelPh: '名前（例：PayPay、Wise）', customValuePh: '支払い情報またはリンク',
    checking: '確認中…',
    noRights: '@{login} さんにはリポジトリを変更する権限がありません。支払い方法を追加できるのはメンバーだけです——オーナーに連絡してください。',
    badToken: 'トークンが無効です。すべてコピーできているか確認してください。', error: 'エラー：{m}',
    loadingMine: 'あなたの情報を読み込み中…', loadFail: '読み込めませんでした：{m}',
    fixFields: '赤く表示された項目を修正してください。', needOne: '支払い方法を 1 つ以上追加してください。',
    saving: '保存中…', saved: '保存しました！約 1 分後にサイトに反映されます。',
    conflict: 'ファイルが変更されました。ページを再読み込みしてもう一度お試しください。', saveErr: '保存エラー：{m}',
    confirmDelete: 'サイトからあなたの情報を削除しますか？', deleting: '削除中…', deleted: '情報を削除しました。', delErr: '削除エラー：{m}',
    copyBtn: 'コピー', code: 'コード', demo: 'デモ', remove: '削除', close: '閉じる',
    needLabel: '方法の名前を入力してください', looksWrong: '間違っているかもしれません：{hint}',
    'hint.trc20': 'TRON ネットワークのアドレス（T で始まる）', 'hint.tron': 'TRON アドレス（T で始まる）',
    'hint.monobank': 'カード番号または send.monobank.ua の募金リンク', 'hint.tbank': 'カード番号、電話番号（SBP）またはリンク',
    'hint.ton': 'TON アドレス（48 文字）', 'hint.btc': 'ビットコインアドレス', 'hint.eth': 'イーサリアムアドレス（0x で始まる）',
    'hint.paypal': 'paypal.me のリンクまたはメールアドレス', 'hint.boosty': 'リンク https://boosty.to/...', 'hint.kofi': 'リンク https://ko-fi.com/...',
    'hint.custom': '自由な支払い情報：名前と内容'
  };

  D.ko = {
    'nav.home': '홈', 'nav.projects': '프로젝트', 'nav.support': '후원', 'nav.join': '참여하기', 'nav.lang': '언어',
    ribbon: '★ HOLY VIBECODE ★ ホーリー・バイブコード ★ 모든 플랫폼 ★ 모든 레벨 ★ 전 세계의 바이브코더 ★ ',
    'meta.desc': 'Holy VibeCode — 전 세계 바이브코더들의 프로젝트를 모은 오픈 컬렉션.',
    'hero.lead': '전 세계 바이브코더들의 프로젝트를 모은 오픈 컬렉션입니다. 어떤 플랫폼이든, 어떤 기술 스택이든, 어떤 실력이든 괜찮아요. 첫 “Hello, World!”부터 완성된 제품까지.',
    'hero.cta1': '프로젝트 보기', 'hero.cta2': '작가 후원하기',
    'stat.authors': '작가', 'stat.projects': '프로젝트', 'stat.support': '후원 가능',
    'girl.aria': 'Holy VibeCode 마스코트',
    'f1.t': '모두를 위해', 'f1.d': '초보자와 전문가, 디자이너, 음악가, 아티스트까지 AI와 함께 무언가를 만드는 모든 사람.',
    'f2.t': '제한 없음', 'f2.d': '웹, 모바일 앱, 게임, 봇, AI 에이전트, 유틸리티와 실험작까지.',
    'f3.t': '작가 후원', 'f3.d': '참여자가 직접 결제 수단을 올려 두니, 좋아하는 프로젝트를 바로 후원할 수 있어요.',
    'proj.title': '프로젝트', 'proj.sub': '목록은 저장소 폴더를 바탕으로 자동으로 만들어집니다.',
    'sup.title': '후원',
    'sup.sub': '저장소 참여자들이 이곳에 결제 수단을 올립니다. 각자 자신의 정보만 추가하고 수정할 수 있으며, 사이트가 GitHub로 사용자 이름을 확인합니다.',
    'sup.add': '내 결제 수단 추가',
    'login.title': 'GitHub로 로그인',
    'login.desc_html': '이 사이트는 서버 없이 동작하므로 로그인하려면 GitHub 개인 토큰이 필요합니다. 토큰은 이 브라우저 탭에만 저장되며 <code>api.github.com</code>으로만 전송됩니다.',
    'login.s1_html': `${tokenLink('토큰 생성 페이지')}를 엽니다 (유형은 <b>classic</b>, <code>public_repo</code>는 이미 체크되어 있어요).`,
    'login.s2_html': '<b>Generate token</b>을 누르고 복사합니다.',
    'login.s3': '아래에 토큰을 붙여 넣습니다.',
    'login.btn': '로그인',
    'form.who': '자신의 정보만 수정할 수 있습니다', 'form.logout': '로그아웃',
    'form.name': '표시 이름', 'form.name.ph': '불리고 싶은 이름',
    'form.msg': '후원자에게 남길 메시지', 'form.msg.ph': '예: 후원금을 어디에 쓸지',
    'form.methods': '결제 수단', 'form.optional': '모든 항목은 선택 사항입니다',
    'form.warn': '저장소는 공개되어 있습니다. 입력한 내용은 누구나 볼 수 있으니 공개하고 싶지 않은 정보는 넣지 마세요.',
    'form.delete': '내 정보 삭제', 'form.save': '저장',
    'join.title': '참여 방법',
    'j1.t': 'DM 보내기', 'j1.note': '프로젝트 이름, 하는 일, 코드나 데모 링크를 알려 주세요.',
    'j2.t': '폴더 만들기', 'j2.d': 'GitHub 사용자 이름으로 폴더를 만들고, 그 안에 프로젝트마다 폴더를 하나씩 만드세요.',
    'j2.note_html': '프로젝트 폴더에 <code>index.html</code>이 있으면 사이트에 “데모” 버튼이 나타납니다.',
    'j3.t': '릴리스 올리기', 'j3.d_html': '프로젝트 하나에 릴리스 하나, 아카이브 하나. 모든 버전을 <code>프로젝트이름_작가.zip</code>에 담으세요.',
    'j3.btn': '릴리스 열기',
    footer: '바이브코더가 바이브코더를 위해 ♥ 담아 만들었어요',
    copied: '복사했어요!', copyFail: '복사하지 못했어요', maxMethods: '최대 {n}개까지 추가할 수 있어요',
    phrases: ['어서 와, 바이브코더!', '네 프로젝트를 세상에 보여 줘 ★', '어떤 플랫폼이든 좋아!', 'Hello, World!부터 시작해도 괜찮아', '“후원” 탭에서 작가를 응원해 줘 ♥', '바이브코딩은 마법이야 ✧', '누군가 지금 꿈의 프롬프트를 쓰고 있어…'],
    'projCount.other': '프로젝트 {n}개',
    emptyProjects: '아직 프로젝트가 없어요. 첫 번째가 되어 보세요!',
    emptySupT: '아직 아무도 결제 수단을 추가하지 않았어요', emptySupD: '저장소 참여자는 위 버튼으로 추가할 수 있어요.',
    errRate: 'GitHub 요청 한도에 도달했어요. 몇 분 뒤에 다시 시도해 주세요.', errLoad: 'GitHub에서 데이터를 불러오지 못했어요.',
    customLabel: '직접 입력', otherLabel: '기타', customLabelPh: '이름 (예: 토스, 카카오페이)', customValuePh: '결제 정보 또는 링크',
    checking: '확인 중…',
    noRights: '@{login} 님은 이 저장소를 수정할 권한이 없어요. 결제 수단은 참여자만 추가할 수 있으니 소유자에게 연락해 주세요.',
    badToken: '토큰이 맞지 않아요. 전체를 복사했는지 확인해 주세요.', error: '오류: {m}',
    loadingMine: '정보를 불러오는 중…', loadFail: '불러오지 못했어요: {m}',
    fixFields: '빨간색으로 표시된 항목을 고쳐 주세요.', needOne: '결제 수단을 하나 이상 추가해 주세요.',
    saving: '저장 중…', saved: '저장했어요! 약 1분 뒤 모두에게 사이트에 반영돼요.',
    conflict: '파일이 변경됐어요. 페이지를 새로고침한 뒤 다시 시도해 주세요.', saveErr: '저장 오류: {m}',
    confirmDelete: '사이트에서 내 정보를 삭제할까요?', deleting: '삭제 중…', deleted: '정보를 삭제했어요.', delErr: '삭제 오류: {m}',
    copyBtn: '복사', code: '코드', demo: '데모', remove: '삭제', close: '닫기',
    needLabel: '결제 수단 이름을 입력해 주세요', looksWrong: '잘못된 것 같아요: {hint}',
    'hint.trc20': 'TRON 네트워크 주소, T로 시작', 'hint.tron': 'TRON 주소, T로 시작',
    'hint.monobank': '카드 번호 또는 send.monobank.ua 모금함 링크', 'hint.tbank': '카드 번호, 전화번호(SBP) 또는 링크',
    'hint.ton': 'TON 주소 (48자)', 'hint.btc': '비트코인 주소', 'hint.eth': '이더리움 주소, 0x로 시작',
    'hint.paypal': 'paypal.me 링크 또는 이메일', 'hint.boosty': '링크 https://boosty.to/...', 'hint.kofi': '링크 https://ko-fi.com/...',
    'hint.custom': '자유 입력: 이름과 값'
  };

  const STORE = 'hv-lang';
  function detect() {
    try { const s = localStorage.getItem(STORE); if (D[s]) return s; } catch { /* ignore */ }
    for (const l of navigator.languages || [navigator.language || 'en']) {
      const c = String(l).toLowerCase().slice(0, 2);
      if (D[c]) return c;
    }
    return 'en';
  }

  let lang = detect();

  function t(key, vars) {
    let s = (D[lang] && D[lang][key]) ?? D.en[key] ?? D.ru[key] ?? key;
    if (typeof s === 'string' && vars) s = s.replace(/\{(\w+)\}/g, (m, k) => (k in vars ? String(vars[k]) : m));
    return s;
  }
  function plural(base, n) {
    let cat = 'other';
    try { cat = new Intl.PluralRules(lang).select(n); } catch { /* ignore */ }
    const key = `${base}.${cat}`;
    const has = (D[lang] && D[lang][key]) || D.en[key];
    return t(has ? key : `${base}.other`, { n });
  }

  function apply(root = document) {
    document.documentElement.lang = lang;
    root.querySelectorAll('[data-i18n]').forEach((n) => {
      const k = n.dataset.i18n;
      if (k.endsWith('_html')) n.innerHTML = t(k); else n.textContent = t(k);
    });
    root.querySelectorAll('[data-i18n-ph]').forEach((n) => { n.placeholder = t(n.dataset.i18nPh); });
    root.querySelectorAll('[data-i18n-aria]').forEach((n) => { n.setAttribute('aria-label', t(n.dataset.i18nAria)); });
    const meta = document.querySelector('meta[name="description"]');
    if (meta) meta.content = t('meta.desc');
  }

  function setLang(l) {
    if (!D[l] || l === lang) return;
    lang = l;
    try { localStorage.setItem(STORE, l); } catch { /* ignore */ }
    apply();
    document.dispatchEvent(new CustomEvent('langchange', { detail: l }));
  }

  window.I18N = { t, plural, apply, setLang, langs: LANGS, get lang() { return lang; } };
})();
