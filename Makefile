CC := gcc
RM := rm -f

memcached_obj := memcached-win64-1.4.24a.exe

# globals.o
memcached_objs := assoc.o cache.o hash.o items.o
memcached_objs += memcached.o slabs.o thread.o util.o
memcached_objs += stats.o jenkins_hash.o murmur3_hash.o
memcached_objs += win32/dummy_defs.o win32/ntservice.o win32/win32.o win32/strtok_r.o win32/getsubopt.o

memcached_cflags := -g3 -O0 -std=gnu99 -fno-strict-aliasing
memcached_cflags += -Wall -Wstrict-prototypes -Wmissing-prototypes
memcached_cflags += -Wmissing-declarations -Wredundant-decls 
memcached_cflags += -DHAVE_STRUCT_TIMESPEC -DHAVE_CONFIG_H
memcached_cflags += -Iwin32 
memcached_cflags += -I../libevent-2.0.11-stable -I../libevent-2.0.11-stable/include 
memcached_cflags += -I../pthreads-w32_64-dll-2-9-1-release/include

memcached_ldflags := -L../pthreads-w32_64-dll-2-9-1-release/lib/x64
memcached_ldflags += -L../libevent-2.0.11-stable
memcached_ldflags += -lpthread -levent -lws2_32 

all: murmur3_hash.o jenkins_hash.o ${memcached_obj}

${memcached_obj}: ${memcached_objs}
	${CC} -o ${memcached_obj} ${memcached_objs} ${memcached_ldflags}

%.o: %.c
	${CC} ${memcached_cflags} -c $< -o $@

clean:
	${RM} ${memcached_objs} ${memcached_obj}
