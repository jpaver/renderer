#ifndef TEXTURE_H
#define TEXTURE_H

#include "geometry.h"
#include "image.h"

typedef struct texture texture_t;
typedef struct cubemap cubemap_t;

/* texture management */
texture_t *texture_from_file(const char *filename);
texture_t *texture_from_image(image_t *image);
void texture_release(texture_t *texture);
void texture_srgb2linear(texture_t *texture);
vec4_t texture_sample(texture_t *texture, vec2_t texcoord);

/* cubemap management */
cubemap_t *cubemap_from_files(const char *positive_x, const char *negative_x,
                              const char *positive_y, const char *negative_y,
                              const char *positive_z, const char *negative_z);
cubemap_t *cubemap_from_images(image_t *positive_x, image_t *negative_x,
                               image_t *positive_y, image_t *negative_y,
                               image_t *positive_z, image_t *negative_z);
void cubemap_release(cubemap_t *cubemap);
void cubemap_srgb2linear(cubemap_t *cubemap);
vec4_t cubemap_sample(cubemap_t *cubemap, vec3_t direction);

#endif
