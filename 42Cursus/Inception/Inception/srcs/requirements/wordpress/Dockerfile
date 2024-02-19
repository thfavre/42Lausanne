FROM debian:buster

RUN apt upgrade && apt -y update

# to be able to download wordpress
RUN apt-get -y install wget


RUN apt-get install -y php7.3\
						php-fpm\
						php-mysql\
						mariadb-client
RUN wget https://fr.wordpress.org/wordpress-6.4.2-fr_FR.tar.gz -P /var/www

RUN cd /var/www && tar -xzf wordpress-6.4.2-fr_FR.tar.gz && rm wordpress-6.4.2-fr_FR.tar.gz

RUN chown -R root:root /var/www/wordpress

COPY ./conf/www.conf /etc/php/7.3/fpm/pool.d/

EXPOSE 9000

COPY ./tools/wp-config.sh /usr/local
# give persmissions
RUN chmod +x usr/local/wp-config.sh


RUN mkdir -p /run/php
#Launch PHP FPM in foreground and ignore deamonize from conf file (-F)
# CMD ["/usr/sbin/php-fpm7.3", "-F"]
ENTRYPOINT ["sh", "/usr/local/wp-config.sh"]
