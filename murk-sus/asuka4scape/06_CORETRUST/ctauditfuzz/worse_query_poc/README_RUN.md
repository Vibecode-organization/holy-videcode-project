# worse_query на 27.2 — статус запуска

Источник: github.com/forcequitOS/worse_query (GPL-3), заявленная поддержка iOS 26.0–26.7.2 / 27.2.
Техника: App Group (class 7) + part=3 (Library/Caches) + подмена Caches на symlink ->
containermanagerd выдаёт sandbox extension на цель; extension consume -> доступ вне sandbox.

Интеграция: worse_query.m встроен в ctoracle (Theos, arm64), приложение подписано нашим
distribution-профилем (app groups group.8e0bc870a21520b9.1..5 присутствуют в CD).
wq_probe() перебирает цели:
  /var/containers/Shared/SystemGroup
  /var/mobile/Containers/Data/Application
  /var/mobile/Containers/Shared/AppGroup
  /var/containers/Data/System
и логирует handle + листинг.

Блокер запуска: телефон снят с USB (lsusb пуст), устройство в локе.
Автозапуск: /tmp/opencode/auto_wq.sh (watchdog) + /tmp/opencode/wq_watch.sh.
Когда iPhone появится на USB и будет разблокирован, watcher сам:
  launch -> pull Documents/oracle.log -> при "wq handle" кладёт /tmp/opencode/WQ_LOG.txt
  и /tmp/opencode/WQ_SUCCESS.
