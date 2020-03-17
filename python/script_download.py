# script_download.py
import urllib.request
import time

url = 'https://picsum.photos/id/{}/200/300'
args = [(n, url.format(n)) for n in range(20)]
start = time.time()
for pic_id, url in args:
    res = urllib.request.urlopen(url)
    pic = res.read()
    with open(f'./{pic_id}.jpg', 'wb') as f:
        f.write(pic)
    print(f'Picture {pic_id} saved!')
end = time.time()
msg ='Operation took {:.3f} seconds to complete.'
print(msg.format(end-start))
