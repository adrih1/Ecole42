# Utiliser une base Debian stable
FROM debian:bullseye

# Installer PHP, ses extensions nécessaires
RUN apt-get update && apt-get upgrade && apt-get install -y \
    wget \
    php7.3 \
    php-fpm \
    php-mysql \ 
    mariadb-client && rm -rf /var/lib/apt/lists/*

RUN mkdir -p /run/php

#Copy the script, asdd right to execute 
COPY ./tools/conf/wordpress_conf.sh /usr/local/bin
RUN chmod +x /usr/local/bin/wordpress_conf.sh

WORKDIR /var/www/html

RUN mkdir -p /var/www/html
RUN chown -R www-data:www-data /var/www/html

ENTRYPOINT ["/usr/local/bin/wordpress_conf.sh"]