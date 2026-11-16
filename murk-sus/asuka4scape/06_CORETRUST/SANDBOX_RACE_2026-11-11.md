# Full sandbox escape — MCM race run (2026-11-11)

## 1. `sbracer` (первый вариант)

Собран/подписан/установлен `app.lake9674.aquila8809.sbracer`
(исходник `06_CORETRUST/ctlab/sbracer/main.m`, добавлен лог в Documents).

Запуск на 27.2/24B115:

```
=== sbracer start uid=501 pid=895
group=group.8e0bc870a21520b9.1
part=/private/var/mobile/Containers/Shared/AppGroup/4F933082.../Library/Caches
valid=/private/var/containers/Shared/SystemGroup/systemgroup.com.apple.mobilegestaltcache/Library/Caches
pre opendir prefs=0x0 errno=1
static query token=2 path=(null)
static win? 0
```

- Статический запрос class 7/part 3 на валидный SystemGroup **выдаёт token**
  (handle 2), но `testWin` (opendir/write `/var/mobile/Library/Preferences`)
  не проходит — токен не на `/`.
- Агрессивная гонка (2 swapper-потока без задержки + 20k query) **повесила
  приложение**: процесс жив, лог не двигается, `done` нет; похоже на deadlock
  MCM при постоянной подмене symlink. Процесс убит (SIGKILL).

## 2. `sbracer2` (новый вариант)

`06_CORETRUST/sbracer2_app`:

- один swapper (не два), `usleep(20)` в цикле;
- `usleep(200)` **между `container_query_get_single_result` и
  `container_copy_sandbox_token`** — чтобы расширить окно, если токен
  резолвит путь заново;
- 50k итераций, лог каждые 1000;
- bundle id `app.lake9674.aquila8809.sbracer2`.

Собран и подписан: `/tmp/sbracer2-signed.ipa`.

**Запуск:** установлен, запущен. Лог дошёл до `iter 7000` без `WIN`;
затем устройство перестало отвечать на lockdown (`No device found`,
`apps query` пуст), `diagnostics restart` не помог. Похоже на MCM deadlock/
hang системы, а не на победу гонки. `Documents/sbracer2.log` не вытащен —
нужен ребут/разблокировка.

Если после ребута в логе есть `WIN: wrote ...` — это полный escape; если
только `iter N` и нет `done` — гонка снова повесила MCM.

## 3. Если гонка не даст WIN

Следующие пути:

1. Аудит MCM `container_copy_sandbox_token` / `realPathForURL`: кэшируется ли
   путь контейнера до выдачи токена. Если да — symlink race бесполезен,
   нужен другой баг MCM.
2. `installd` app replacement / data-container handover (root FS 27.2 +
   `InstalledContentLibrary`/`ContainerManagerCommon`).
3. `sharingd`/AirDrop, SpringBoard/ImageIO icon path — userland parsers.
4. Partial MCM escape (class 7) использовать для записи в SystemGroup
   контейнеры `installd`/`containermanagerd` и искать, что они читают оттуда.

## 4. Ограничение

Полного `/` escape пока нет. `sbracer2` — проверка гипотезы TOCTOU; без
телефона её не завершить.
