import re

TOK = re.compile(r'''
    ;[^\n]*                      # comment
  | \#"(?:[^"\\]|\\.)*"          # regex literal
  | \(
  | \)
  | "(?:[^"\\]|\\.)*"            # string
  | [^\s();#]+                   # atom
''', re.X)


def parse(s):
    toks = TOK.findall(s)
    pos = 0

    def rd():
        nonlocal pos
        t = toks[pos]
        pos += 1
        if t == '(':
            lst = []
            while toks[pos] != ')':
                if toks[pos].startswith(';'):
                    pos += 1
                    continue
                lst.append(rd())
            pos += 1
            return lst
        return t

    out = []
    while pos < len(toks):
        if toks[pos].startswith(';'):
            pos += 1
            continue
        out.append(rd())
    return out


def walk(node, fn):
    fn(node)
    if isinstance(node, list):
        for c in node:
            walk(c, fn)
