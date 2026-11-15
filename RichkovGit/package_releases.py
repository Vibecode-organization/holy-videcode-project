"""Package published RichkovGit assets without rebuilding or changing binaries."""
import hashlib
import json
from pathlib import Path
import sys
import urllib.request
import zipfile

root = Path(__file__).resolve().parent
projects = json.loads((root / 'releases.json').read_text())
project = next(p for p in projects if p['repo'] == sys.argv[1])
output = Path('richkovgit-dist') / project['repo']
output.mkdir(parents=True, exist_ok=True)
readme = f"""{project['title']}
Версия: {project['version']}{' (preview)' if project['prerelease'] else ''}
Платформы: {project['platforms']}
Описание: {project['description']}

{project['install']}

Исходники, лицензии, полная инструкция: https://github.com/RichkovGit/{project['repo']}
Оригинальные сборки: {project['source_release']}
Автор/сопровождение: https://github.com/RichkovGit

Файлы опубликованных сборок не изменены. SHA-256 каждого файла проверен
по метаданным оригинального GitHub-релиза перед упаковкой.
"""
destinations = [a['destination'] for a in project['assets']]
assert len(destinations) == len(set(destinations))
archive = output / project['zip']
with zipfile.ZipFile(archive, 'w', zipfile.ZIP_DEFLATED) as z:
    z.writestr('README.txt', readme)
    sums = []
    for asset in project['assets']:
        assert asset['url'].startswith(f"https://github.com/RichkovGit/{project['repo']}/releases/download/")
        assert not Path(asset['destination']).is_absolute() and '..' not in Path(asset['destination']).parts
        target = output / asset['name']
        digest = hashlib.sha256()
        with urllib.request.urlopen(asset['url'], timeout=120) as response, target.open('wb') as stream:
            while chunk := response.read(1024 * 1024):
                digest.update(chunk)
                stream.write(chunk)
        assert 'sha256:' + digest.hexdigest() == asset['digest'], asset['name']
        z.write(target, asset['destination'])
        sums.append(f"{digest.hexdigest()}  {asset['destination']}")
        target.unlink()
    z.writestr('CONTENTS_SHA256SUMS.txt', '\n'.join(sums) + '\n')
with zipfile.ZipFile(archive) as z:
    assert z.testzip() is None
    assert set(z.namelist()) == set(destinations) | {'README.txt', 'CONTENTS_SHA256SUMS.txt'}
notes = f"""Версия: {project['version']}{' (preview)' if project['prerelease'] else ''}
Платформы: {project['platforms']}
Описание: {project['description']}
Ссылки: https://github.com/RichkovGit/{project['repo']}
Оригинальный релиз: {project['source_release']}

Скачайте {project['zip']}; внутри README.txt с инструкцией по установке.
SHA-256 архива: `{hashlib.file_digest(archive.open('rb'), 'sha256').hexdigest()}`
"""
(output / 'notes.md').write_text(notes)
print(f"Verified {len(destinations)} original assets; ZIP integrity OK: {archive}")
