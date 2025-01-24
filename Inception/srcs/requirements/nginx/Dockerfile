# Use last stable version
FROM debian:bullseye

# Install dependencies for NGINX with TLS
RUN apt-get update &&  apt-get upgrade && apt-get install -y \
    nginx \
    openssl \
    && apt-get clean \
    && rm -rf /var/cache/apk/*

# Create directories 
RUN mkdir -p /run/nginx /etc/nginx/conf.d /etc/nginx/certs

# Copy the config file 
COPY nginx.conf /etc/nginx/nginx.conf

# Copy the certifcates in the container
COPY certs/server.crt /etc/nginx/certs
COPY certs/server.key /etc/nginx/certs

# Expose HTTPS port
EXPOSE 443

# Launch NGINX  || Daemon.off means that nginx must not run in the background it stays in the foreground
CMD ["nginx", "-g", "daemon off;"]


