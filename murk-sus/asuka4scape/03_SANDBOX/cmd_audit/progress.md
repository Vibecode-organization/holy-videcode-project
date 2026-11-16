## 2026-10-29 — containermanagerd XPC (subagent AM)
- dsc 27.2: ContainerManagerSystem/User — пустые __TEXT; весь код в ContainerManagerCommon (sha256 400738ae…).
- Слушатель: block invoke 0x207e4697c, 39 классов команд; ключ "Command" (uint64), 0x207e18b84.
- Диспетчер: preflight → execute; notEntitled 0x37/3 (0x207e14548).
- Без preflight-энтайтлмента: 32, 36, 38, 39, 45; 45 отваливается на container-required (err 0x12).
- Per-container: 0x207e10d90, сравнение identifier 0x207e10f38; Query — отказ на весь запрос, 0x207e2424c.
- Persona: 0x207e069c0 (err 0x4c); audit token — xpc_dictionary_get_audit_token 0x207e07dc0; proxy — 0x207e0b334.
- CreateOrLookupWithBundle: preflight=YES 0x207ea612c, id из подписи бандла 0x207ea67c0, гейт 0x207ea6294.
- Итог: чужой контейнер/id не получить; остаток — мультиюзер/relay (не подтверждено).
- Отчёт: work/cmd_audit/REPORT.md.
