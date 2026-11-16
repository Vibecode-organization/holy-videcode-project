#!/usr/bin/env python3
# sb272 s-expression walker: pull every mach-lookup rule out of the app profiles.
import json, re, sys, os

ALL = '/home/femboychik/work/sb272/all.json'


def tokenize(s):
    i, n = 0, len(s)
    while i < n:
        c = s[i]
        if c in ' \t\r\n':
            i += 1
        elif c == ';':                      # comment to EOL
            while i < n and s[i] != '\n':
                i += 1
        elif c in '()':
            yield c
            i += 1
        elif c == '"':
            j = i + 1
            buf = []
            while j < n:
                if s[j] == '\\':
                    buf.append(s[j + 1]); j += 2
                elif s[j] == '"':
                    break
                else:
                    buf.append(s[j]); j += 1
            yield ('str', ''.join(buf))
            i = j + 1
        elif c == '#':
            m = re.match(r'#"(?:[^"\\]|\\.)*"', s[i:])
            if m:
                yield ('str', m.group(0)[2:-1])
                i += len(m.group(0))
            else:
                i += 1
        else:
            j = i
            while j < n and s[j] not in ' \t\r\n()";':
                j += 1
            yield ('sym', s[i:j])
            i = j


def parse(s):
    stack = [[]]
    for t in tokenize(s):
        if t == '(':
            stack.append([])
        elif t == ')':
            top = stack.pop()
            stack[-1].append(top)
        else:
            stack[-1].append(t)
    return stack[0]


def sym(x):
    return x[1] if isinstance(x, tuple) else None


def walk(node, path=()):
    if isinstance(node, list):
        if node and sym(node[0]) in ('allow', 'deny', 'autobox'):
            yield path, node
            return
        for ch in node:
            yield from walk(ch, path)


def head(n):
    return sym(n[0]) if isinstance(n, list) and n else None


def collect(n, op, out):
    """collect (op "value") leaves"""
    if not isinstance(n, list):
        return
    if head(n) == op:
        for a in n[1:]:
            if isinstance(a, tuple) and a[0] == 'str':
                out.append(a[1])
        return
    for a in n[1:]:
        collect(a, op, out)


def gate(n):
    """classify a mach-lookup rule body -> (kind, detail)"""
    txt = repr(n)
    has_disable = 'disable-enforcement' in txt
    ents = []
    collect(n, '%entitlement-is-present', ents)
    collect(n, '%entitlement-is-bool-true', ents)
    flags = []
    collect(n, 'profile-flag', flags)
    flags = [f for f in flags if f != 'disable-enforcement']
    ops = set()
    for a in n[1:]:
        if isinstance(a, list) and head(a):
            ops.add(head(a))
    if has_disable and not ents:
        return 'inactive', 'disable-enforcement'
    if ents:
        return 'entitled', ','.join(sorted(set(ents)))
    if flags:
        return 'flagged', ','.join(sorted(set(flags)))
    if not ops or ops <= {'mach-lookup'}:
        return 'open', ''
    return 'open', ''


def main():
    data = {e['name']: e['sbpl'] for e in json.load(open(ALL))}
    rows = []
    for prof in ('baseline', 'container'):
        tree = parse(data[prof])
        for path, n in walk(tree):
            if head(n) != 'allow' or len(n) < 2 or sym(n[1]) != 'mach-lookup':
                continue
            names = []
            collect(n, 'global-name', names)
            reqany = 'require-any' in repr(n)
            kind, detail = gate(n)
            rows.append(dict(profile=prof, names=names, reqany=reqany,
                             kind=kind, detail=detail, src=repr(n)[:400]))
    json.dump(rows, open('/home/femboychik/work/svc_map/machlookup_raw.json', 'w'), indent=1)
    # per-name effective classification: open wins over entitled wins over inactive
    rank = {'open': 0, 'flagged': 1, 'entitled': 2, 'inactive': 3}
    best = {}
    for r in rows:
        if not r['names']:
            continue
        for nm in r['names']:
            cur = best.get(nm)
            if cur is None or rank[r['kind']] < rank[cur['kind']]:
                best[nm] = dict(kind=r['kind'], detail=r['detail'], profile=r['profile'])
    json.dump(best, open('/home/femboychik/work/svc_map/machlookup_best.json', 'w'), indent=0, sort_keys=True)
    from collections import Counter
    print('rules', len(rows), Counter(r['kind'] for r in rows))
    print('unique names', len(best), Counter(v['kind'] for v in best.values()))
    empty = [r for r in rows if not r['names']]
    print('nameless rules', len(empty))
    for r in empty:
        print('  ', r['profile'], r['kind'], r['src'][:160])


main()
