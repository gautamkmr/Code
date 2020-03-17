import urllib.request
import time

def download_img(pic_id, url):
    res = urllib.request.urlopen(url)
    pic = res.read()
    with open(f'./{pic_id}.jpg', 'wb') as f:
        f.write(pic)
    print(f'Picture {pic_id} saved!')

def main():
    url = 'https://picsum.photos/id/{}/200/300'
    args = [(n, url.format(n)) for n in range(20)]
    start = time.time()
    for _ in map(download_img, args[0], args[1]):
        pass
    end = time.time()
    msg = 'Operation took {:.3f} seconds to complete.'
    print(msg.format(end-start))

if __name__ == '__main__':
    main()
