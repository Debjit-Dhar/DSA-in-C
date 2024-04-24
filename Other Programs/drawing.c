#include <stdio.h>
#include <mpg123.h>
#include <ao/ao.h>

int main()
{
// Initialize libmpg123 and libao
mpg123_init();
ao_initialize();

Copy code
// Declare a file pointer and a buffer to store the data
FILE *mp3_file;
char buffer[1024];

// Open the .MP3 file using fopen()
mp3_file = fopen("tchaikovsky-dance-of-the-sugar-plum-fairy.mp3", "rb");

// Check if the file was successfully opened
if(mp3_file == NULL)
{
    printf("Error opening .MP3 file\n");
    return 1;
}

// Create a mpg123 decoder handle
mpg123_handle *decoder = mpg123_new(NULL, NULL);

// Set the input file for the decoder
mpg123_open_fd(decoder, fileno(mp3_file));

// Get the audio format
long rate;
int channels, encoding;
mpg123_getformat(decoder, &rate, &channels, &encoding);

// Set up libao
ao_sample_format format;
format.bits = mpg123_encsize(encoding) * 8;
format.rate = rate;
format.channels = channels;
format.byte_format = AO_FMT_NATIVE;
format.matrix = 0;

// Open the audio device
ao_device *device = ao_open_live(ao_default_driver_id(), &format, NULL);

// Read and play the audio data
size_t bytes_read;
while(mpg123_read(decoder, buffer, 1024, &bytes_read) == MPG123_OK)
{
    ao_play(device, buffer, bytes_read);
}

// Close the audio device and file
ao_close(device);
fclose(mp3_file);

// Clean up
mpg123_delete(decoder);
mpg123_exit();
ao_shutdown();

return 0;
}

