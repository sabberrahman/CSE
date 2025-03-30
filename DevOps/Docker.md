![[Pasted image 20250327113036.png]]

we can run any images even if we didint have it locally.
```sh
docke run -d nginx:1.23
```
`-d` flags allow us to hide the logs and use the current window terminal

```sh
C:\Users\Janik>docker ps
CONTAINER ID   IMAGE        COMMAND                  CREATED         STATUS         PORTS     NAMES
20ecec900a4d   nginx:1.23   "/docker-entrypoint.…"   6 minutes ago   Up 6 minutes   80/tcp    trusting_carson

C:\Users\Janik>docker kill 20ecec900a4d
20ecec900a4d

C:\Users\Janik>docker ps
CONTAINER ID   IMAGE     COMMAND   CREATED   STATUS    PORTS     NAMES

C:\Users\Janik>docker run -d nginx:1.23
5188c9fd923af1a36a49933204516d3421dec4092f2720bd773d755b1ac95a81

C:\Users\Janik>docker ps
CONTAINER ID   IMAGE        COMMAND                  CREATED         STATUS         PORTS     NAMES
5188c9fd923a   nginx:1.23   "/docker-entrypoint.…"   7 seconds ago   Up 7 seconds   80/tcp    sweet_ramanujan

C:\Users\Janik>docker images
REPOSITORY                 TAG       IMAGE ID       CREATED         SIZE
docker/welcome-to-docker   latest    eedaff45e3c7   16 months ago   29.5MB
nginx                      1.23      f5747a42e3ad   22 months ago   214MB

C:\Users\Janik>
```


-----------------
```bash
docker rmi IMAGE_ID
docker rmi IMAGE_NAME
docker rmi docker/welcome-to-docker
docker rmi -f IMAGE_ID


docker stop CONTAINER_ID
docker rm CONTAINER_ID
docker kill CONTAINER_ID

```

![[Pasted image 20250327113958.png]]


```sh
C:\Users\Janik>docker ps
CONTAINER ID   IMAGE        COMMAND                  CREATED         STATUS         PORTS     NAMES
5188c9fd923a   nginx:1.23   "/docker-entrypoint.…"   6 minutes ago   Up 6 minutes   80/tcp    sweet_ramanujan

```

```sh
CONTAINER ID   IMAGE        COMMAND                  CREATED         STATUS         PORTS     NAMES
435f13e3b84b   nginx:1.23   "/docker-entrypoint.…"   8 seconds ago   Up 7 seconds   80/tcp    fervent_diffie
5188c9fd923a   nginx:1.23   "/docker-entrypoint.…"   9 minutes ago   Up 9 minutes   80/tcp    sweet_ramanujan

```

running same images twice. but we cannot--

w cannot access the nginx in port:80, its running on isolated docker?? we need to bind port in order for us to see.

```sh 
docker run -d -p 8000:80 nginx:1.23
```

![[Pasted image 20250327114832.png]]

> ⚠ **Note:**  
> Only one service can run on a specific port on the host.  
> For example, only one service can run on port `9000`.

logs for that server -- 

```sh
C:\Users\Janik>docker logs e226a4d486fe
/docker-entrypoint.sh: /docker-entrypoint.d/ is not empty, will attempt to perform configuration
/docker-entrypoint.sh: Looking for shell scripts in /docker-entrypoint.d/

"/usr/share/nginx/html/favicon.ico" failed (2: No such file or directory), client: 172.17.0.1, server: localhost, request: "GET /favicon.ico HTTP/1.1", host: "localhost:8000", referrer: "http://localhost:8000/"
172.17.0.1 - - [27/Mar/2025:05:53:49 +0000] "GET / HTTP/1.1" 304 0 "-" "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/134.0.0.0 Safari/537.36" "-"
172.17.0.1 - - [27/Mar/2025:05:53:50 +0000] "GET / HTTP/1.1" 304 0 "-" "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/134.0.0.0 Safari/537.36" "-"
172.17.0.1 - - [27/Mar/2025:05:53:50 +0000] "GET / HTTP/1.1" 304 0 "-" "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/134.0.0.0 Safari/537.36" "-"
172.17.0.1 - - [27/Mar/2025:05:53:51 +0000] "GET / HTTP/1.1" 304 0 "-" "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/134.0.0.0 Safari/537.36" "-"

```

---------------------------
```sh
docker run
```
create new container everytime,doesnt re use old container.

to see all runningh and pause container, run 

```sh
docker run ps -a 

C:\Users\Janik>docker ps -a
CONTAINER ID   IMAGE          COMMAND                  CREATED        STATUS                    PORTS     NAMES
ae1443613a21   f5747a42e3ad   "/docker-entrypoint.…"   6 hours ago    Exited (0) 4 hours ago              blissful_einstein
6c4e846009dc   eedaff45e3c7   "/docker-entrypoint.…"   6 hours ago    Exited (0) 6 hours ago              naughty_williams
e226a4d486fe   nginx:1.23     "/docker-entrypoint.…"   37 hours ago   Exited (0) 37 hours ago             elegant_nash

docker stop f5747a42e3ad
```

-------------

```bash
docker run --name website-api -d -p 9000:80 nginx:1.23
```

----

public vs private docker registry
 
docker registry -> a servoce probifinh storeage [aws es2]
-> collection of repo

docker repository -> collection of images with same name but differnet versions

 ![[Pasted image 20250329031217.png]]

dockerfile -> we write docerfile for our application to builf a ocker image from, it 

FROM 
COPY 
WORKDIR
RUN 
CMD -> LAST commod


```dockerfile
FROM node:22-alpine

COPY package.json /app/
COPY src /app/  
  
WORKDIR /app

RUN npm i

CMD ["node", "server.js"]
```



