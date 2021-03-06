#define _POSIX_C_SOURCE 200112L
#define ALSA_PCM_NEW_HW_PARAMS_API
#include <alsa/asoundlib.h>
#include <alloca.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{

    long loops;
    int rc;
    int size;
    snd_pcm_t *handle;
    snd_pcm_hw_params_t *params;
    unsigned int val;
    int dir;
    snd_pcm_uframes_t frames;
    char *buffer;

    // Open PCM device for playback.
    rc = snd_pcm_open(&handle, "default", SND_PCM_STREAM_PLAYBACK, 0);

    if(rc < 0)
    {
        fprintf(stderr, "unable to open pcm device: %s\n", snd_strerror(rc));
        exit(1);
    }

    //Allocate a harware parametrs object.
    snd_pcm_hw_params_alloca(&params);
    //Fill it in with defualt values.
    snd_pcm_hw_params_any(handle, params);
    //set the desired hardware parametrs.
    //Interleaved mode.
    snd_pcm_hw_params_set_access(handle, params, SND_PCM_ACCESS_RW_INTERLEAVED);

    snd_pcm_hw_params_set_format(handle, params, SND_PCM_FORMAT_S16_LE);

    snd_pcm_hw_params_set_channels(handle, params, 2);
    val = 44100;
    snd_pcm_hw_params_set_rate_near(handle, params, &val, &dir);
    frames = 32;
    snd_pcm_hw_params_set_period_size_near(handle, params, &frames, &dir);
    rc = snd_pcm_hw_params(handle, params);

    if(rc < 0)
    {
        fprintf(stderr, "unable to set hw parameters: %s\n", snd_strerror(rc));
        exit(1);
    }

    snd_pcm_hw_params_get_period_size(params, &frames, &dir);

    snd_pcm_prepare(handle);
    printf("%d\n",frames);
    size = frames * 4;
    buffer = (char *)malloc(size);
    snd_pcm_hw_params_get_period_time(params, &val, &dir);
    loops = 5000000/val;
    snd_pcm_hw_params_get_rate(params,&val,&dir);
    printf("%d\n",val);

    while(loops)
    {
        loops--;
        rc = read(0, buffer, size);

        if(rc == 0)
        {
            fprintf(stderr, "end of file input\n");
            break;
        }
        else if(rc != size)
        {
            fprintf(stderr, "short read: read %d bytes\n", rc);

        }

        rc = snd_pcm_writei(handle, buffer, frames);

        if(rc == -EPIPE)
        {
            fprintf(stderr, "underrun occurred\n");
            snd_pcm_prepare(handle);
        }
        else if(rc < 0)
        {
            fprintf(stderr, "error from writei :%s\n", snd_strerror(rc));
        }
        else if(rc != (int)frames)
        {
            fprintf(stderr, "short write, write %d frames\n", rc);
        }
    }
snd_pcm_drain(handle);
snd_pcm_close(handle);
free(buffer);




    return 0;
}

