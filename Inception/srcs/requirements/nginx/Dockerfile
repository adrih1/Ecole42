# Utiliser l'avant derniere version stable
FROM debian:bullseye

RUN apt-get update && apt-get install -y nginx openssl && \
    mkdir -p /etc/nginx/ssl && \
    mkdir -p /var/run/nginx && \
    chmod 755 /var/www/html && \
    chown -R www-data:www-data /var/www/html
    openssl req -x509 -nodes -out /etc/nginx/ssl/server.crt \
	-keyout /etc/nginx/ssl/server.key -subj "/C=FR/ST=IDF/L=Paris/O=42/OU=42/CN=ahors.42.fr/UID=ahors"

# Copier le fichier de configuration nginx
COPY ./tools/conf/nginx.conf /etc/nginx/conf.d/

# Exposer le port HTTPS
EXPOSE 443

# Lancer nginx en avant-plan
CMD ["nginx", "-g", "daemon off;"]