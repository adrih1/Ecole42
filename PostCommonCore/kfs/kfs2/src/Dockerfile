FROM debian:latest

RUN apt-get update && apt-get install -y \
    grub-pc-bin \
    grub-common \
    xorriso \
    mtools \
    libisoburn1 \
    xz-utils \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /os

ENTRYPOINT ["/bin/sh", "-c"]

CMD ["mkdir -p isodir/boot/grub && \
cp .obj/kfs.bin isodir/boot/ && \
cp src/grub.cfg isodir/boot/grub/ && \
grub-mkrescue --compress=xz --fonts= --locales= --themes= -o kfs.iso isodir && \
rm -rf isodir"]
