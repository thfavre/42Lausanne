FROM debian:buster

RUN apt -y update && apt upgrade

RUN apt-get install mariadb-server -y

COPY conf/50-server.cnf	/etc/mysql/mariadb.conf.d/50-server.cnf
# or COPY ./tools/50-server.cnf /etc/mysql/mariadb.conf.d/
# from https://github.com/Forstman1/inception-42/blob/main/srcs/requirements/mariadb/Dockerfile


# RUN chown -R mysql:mysql /var/run/mysqld && \
#         chown -R mysql:mysql /etc/mysql/


COPY ./tools/script.sh /usr/local/
RUN chmod +x /usr/local/script.sh

EXPOSE 3306

# CMD ["/script.sh"]
ENTRYPOINT [ "sh", "/usr/local/script.sh" ]
