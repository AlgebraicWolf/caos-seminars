#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>


int main(int argc, char** argv)
{
    int f_in = open(argv[1], O_RDONLY);
    int f_out_dig = open(argv[2], O_WRONLY | O_CREAT, 0666);
    int f_out_etc = open(argv[3], O_WRONLY | O_CREAT, 0666);
    const size_t buff_cap = 4096;
    char buffer[buff_cap];
    char buffer_out_dig[buff_cap];
    char buffer_out_etc[buff_cap];
    size_t buff_len;
    size_t buffer_out_dig_len = 0;
    size_t buffer_out_etc_len = 0;
    while (buff_len = read(f_in, buffer, buff_cap))
    {
        for (size_t i = 0; i < buff_len; ++i)
        {
            if (isdigit(buffer[i]))
            {
                buffer_out_dig[buffer_out_dig_len++] = buffer[i];
            }
            else
            {
                buffer_out_etc[buffer_out_etc_len++] = buffer[i];
            }
            if (buffer_out_dig_len == buff_cap)
            {
                write(f_out_dig, buffer_out_dig, buff_cap);
                buffer_out_dig_len = 0;
            }
            if (buffer_out_etc_len == buff_cap)
            {
                write(f_out_etc, buffer_out_etc, buff_cap);
                buffer_out_etc_len = 0;
            }
        }
    }
    write(f_out_dig, buffer_out_dig, buffer_out_dig_len);
    write(f_out_etc, buffer_out_etc, buffer_out_etc_len);
    close(f_in);
    close(f_out_dig);
    close(f_out_etc);
}

