# Use last stable version
FROM alpine:3.17

# Install dependencies for NGINX with TLS
RUN apk update && apk add --no-cache \
    nginx \
    openssl \
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
CMD ["nginx", "-g", "daemon.off"]


