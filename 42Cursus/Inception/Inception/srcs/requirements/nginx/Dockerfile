FROM debian:buster

RUN apt upgrade && apt -y update

RUN apt install -y nginx
RUN apt install openssl -y

RUN apt install vim -y

# ssl key
RUN mkdir -p /etc/nginx/ssl
RUN openssl req -x509 -nodes \
	-out /etc/nginx/ssl/inception.crt -keyout /etc/nginx/ssl/inception.key \
	-subj "/C=FR/ST=Lausanne/L=Lausanne/O=42/OU=42/CN='${DOMAIN_NAME}'"

COPY ./conf/nginx.conf /etc/nginx/nginx.conf
# COPY nginx.conf /etc/nginx/sites-available/default

# COPY ./index.html /var/www/html/index.html
# COPY ./index.php /var/www/html/index.php
#  /usr/share/nginx/html/index.html


EXPOSE 443
RUN chmod 755 /var/www/html
RUN chown -R www-data:www-data /var/www/html
CMD ["nginx", "-g", "daemon off;"]
