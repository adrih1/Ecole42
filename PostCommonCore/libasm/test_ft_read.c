#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>

ssize_t ft_read(int fd, void *buf, size_t count);


static void compare_read(int fd1, int fd2, size_t count, const char *test_name)
{
	char	buf1[100];
	char	buf2[100];
	ssize_t	ret1;
	ssize_t	ret2;
	int		err1;
	int		err2;

	memset(buf1, 'A', sizeof(buf1));
	memset(buf2, 'A', sizeof(buf2));

	errno = 0;
	ret1 = read(fd1, buf1, count);
	err1 = errno;

	errno = 0;
	ret2 = ft_read(fd2, buf2, count);
	err2 = errno;

	printf("\n[%s]\n", test_name);
	printf("read    : ret=%zd errno=%d (%s)\n",
		ret1, err1, strerror(err1));
	printf("ft_read : ret=%zd errno=%d (%s)\n",
		ret2, err2, strerror(err2));

	if (ret1 > 0)
		printf("read    buf=\"%.*s\"\n", (int)ret1, buf1);
	if (ret2 > 0)
		printf("ft_read buf=\"%.*s\"\n", (int)ret2, buf2);

	if (ret1 == ret2
		&& err1 == err2
		&& (ret1 <= 0 || memcmp(buf1, buf2, ret1) == 0))
		printf("✅ OK\n");
	else
		printf("❌ FAIL\n");
}



static void test_file(void)
{
	int	fd1;
	int	fd2;

	fd1 = open("test.txt", O_RDONLY);
	fd2 = open("test.txt", O_RDONLY);

	if (fd1 < 0 || fd2 < 0)
	{
		perror("open");
		return ;
	}
	compare_read(fd1, fd2, 50, "FILE READ");

	close(fd1);
	close(fd2);
}

static void test_empty_and_zero(void)
{
	int	fd1;
	int	fd2;

	fd1 = open("test.txt", O_RDONLY);
	fd2 = open("test.txt", O_RDONLY);

	if (fd1 < 0 || fd2 < 0)
		return ;

	compare_read(fd1, fd2, 0, "COUNT = 0");
	compare_read(fd1, fd2, -1, "COUNT = -1");
	
	close(fd1);
	close(fd2);
}

static void test_invalid_fd(void)
{
	compare_read(-1, -1, 10, "FD = -1");
	compare_read(9999, 9999, 10, "FD NON EXISTANT");
}

// static void test_stdin(void)
// {
// 	char	buf1[100];
// 	char	buf2[100];
// 	ssize_t	r1;
// 	ssize_t	r2;

// 	memset(buf1, 0, 100);
// 	memset(buf2, 0, 100);

// 	printf("\n[STDIN]\nType something then press ENTER:\n");

// 	errno = 0;
// 	r1 = read(0, buf1, 99);
// 	printf("read    : ret=%zd buf=\"%s\"\n", r1, buf1);

// 	printf("Type the SAME thing again:\n");
// 	errno = 0;
// 	r2 = ft_read(0, buf2, 99);
// 	printf("ft_read : ret=%zd buf=\"%s\"\n", r2, buf2);
// }

void test_ft_read(void)
{
	test_file();
	test_empty_and_zero();
	test_invalid_fd();
	// test_stdin();
}
