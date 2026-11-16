# Подписать и поставить CFProbe

Нужен один шаг: подпиши `CFProbe-Kai.ipa` тем же дев-профилем, которым подписан
CTProbe (`iPhone Developer: murkuwuwu@gmail.com (LJX7B944WQ)`), и поставь поверх
CTProbe (bundle id `com.smith.krwprobe.873962H52X`, после подписи станет
`...873962H52X.873962H52X`). Запусти приложение, дай 10 секунд, затем:

    pymobiledevice3 apps pull --documents com.smith.krwprobe.873962H52X.873962H52X \
        cfprobe.log /tmp/cfprobe.log

Это проверка `cfprefsd` AnyUser container race: создаёт root-файл в
`/private/var/db`, затем пробует записать LaunchDaemon plist в
`/Library/LaunchDaemons`. Если plist получает содержимое — это root.
MCMProbe-Kai.ipa — следующий тест (class 13 system groups), если CFProbe пуст.
