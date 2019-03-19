import hashlib
import uuid
total = 50
cipherFileName = "cipherText.out"
backupFileName = "backup.out"
open(cipherFileName,'w').close()
open(backupFileName,'w').close()
for index in range(total):
    id = uuid.uuid4()
    hl = hashlib.md5()
    hl.update(str(id).encode(encoding='utf-8'))
    print(hl.hexdigest(),file = open(cipherFileName,'a'))
    print(str(id),file=open(backupFileName,'a'))