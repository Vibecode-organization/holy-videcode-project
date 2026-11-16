## step1 — handler sel 0x44
- таблица 0x8023ad0[0x44] -> 0x9aa42dc (stride 0x28, slot 68).
- дизасм 0x9aa42dc..0x9aa43d4 снят. Структура: opcode=*(u32*)args->scalarInput(+0x20);
  cnt=args->structureInputSize(+0x38)>>3; case 0x11 -> entitlement "com.apple.private.gain-map-access"
  (строка 0x785d744) через stub 0x9abd1cc(GOT 0x8029e50 -> 0xa9dee48), иначе 0xe00002c1;
  case 0x01 и cnt==2 -> cnt=1; case 0x0b -> читает *(u64*)args->structureInput(+0x30)
  и делает atomic add/sub на this+0xfc (stub 0x9abd20c/0x9abd1fc -> 0xa89460c/0xa8945fc, ldadd +/-1).
  ВНИМАНИЕ: ветка 0x0b НЕ зовёт release — зовёт инкремент/декремент счётчика по this+0xfc.
- общий хвост: fb=this+0xd8; x16=fb->vtable; autda key 0xcda1 modifier=fb|0xcda1000000000000;
  slot 0x780 -> braa x16, (slot|0x4ee4<<48); args (fb, opcode, structureInput, cnt).
  => вся логика опкодов уходит в IOMobileFramebuffer::vtable[0x780].
## step2 — fb-объект и настоящий диспетчер
- this->[0xd8] = OSDynamicCast(IOMobileFramebuffer*, provider); provider = AppleCLCD2
  (кест com.apple.driver.AppleMobileDispH14P-DCP, meta 0xaec9b78, size 0x61b8).
- instance vtable AppleCLCD2 = 0x7e71088; слот +0x780 = 0x9a754cc  <-- РЕАЛЬНЫЙ обработчик sel 0x44.
- 0x9a754cc: switch(opcode){0,9,0xb,0x14,0x1c}, default -> vtable+0xa28 (0x9a884a8).
  * 0xb: требует count==1 (т.е. structureInputSize 8..15); берёт in[0], НЕ разыменовывает как
    объект, а только (in[0]!=0) -> bool -> 0x9a932e4(this->[0x438], bool, 0). release НЕТ.
  * 0x14: bool -> vtable[0x788](this,bool,this).  * 0x1c: bool -> IOCommandGate::runAction.
  * default 0x9a884a8: count>=5 -> 0xe00002c2; иначе копия <=4 qwords в фикс. буфер 0x28 и
    вызов vtable[0x8b0](this, 0x41353030, &buf, 0x28, &out, 4). Указатели не разыменовываются.
## step3 — проверки
- 0x9aa4358: чтение *(u64*)args->structureInput БЕЗ NULL-чека (в отличие от sel 0x4e, где cbz есть).
  => opcode 0xb при structureInput==NULL -> NULL-deref -> panic. Кандидат в DoS, требует проверки на устройстве.
- this+0xfc: инициализируется 0 (0x9aa14ac); в close-пути 0x9aa17d0 крутит
  atomic_dec_return(this+0xfc) и повторяет fb->vtable[0x780](fb, 0xb, &zero, 1), пока >0. Т.е. это счётчик
  "gain-map enabled", а не refcount объекта.
- sel 0x4e: client 0x9aa3d3c -> fb vtable+0x720 = 0x9a742f4 -> 0x9a73db8, там lookup по таблице
  0x9a9a360 и проверка size >= max(desc+8, desc+4) перед чтением; затем DCP.
- sel 0x4f: client 0x9aa3e34 -> fb vtable+0x728 = 0x9a74528 (op 0x87/0xbc) -> vtable+0x890 -> DCP.
## step4 — отчёт готов
- REPORT.md записан (полный дизасм 0x9aa42dc и 0x9a754cc, таблица опкодов, PAC, 0x4e/0x4f, вердикты).
- CHAT_дипсики.md: добавлена запись "## MFB sel 0x44 (subagent I)".
- Итог: type confusion/release опровергнуты; единственный дефект — NULL-deref 0x9aa4358 (не подтверждён на устройстве).
