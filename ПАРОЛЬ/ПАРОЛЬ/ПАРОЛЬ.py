
import random
import string
token = ''.join(random.choice(string.ascii_uppercase + string.ascii_lowercase + string.digits) for x in range(30)) 
print(token)