# Utiliser une base Debian stable
FROM debian:bullseye

ENV DEBIAN_FRONTEND=noninteractive

# Installer PHP, ses extensions nécessaires
RUN apt-get update && apt-get upgrade -y && apt-get install -y \
    wget \
    php-fpm \
    php-mysql \ 
    && rm -rf /var/lib/apt/lists/*

RUN mkdir -p /run/php/

#Copy the script, asdd right to execute 
COPY ./tools/wordpress_conf.sh /usr/local/bin
RUN chmod +x /usr/local/bin/wordpress_conf.sh


RUN mkdir -p /var/www/html
RUN chown -R www-data:www-data /var/www/html

ENTRYPOINT ["wordpress_conf.sh"]
