#ifndef TEXTURE2D_H
#define TEXTURE2D_H

#include <glad/glad.h>
#include "stb_image.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Texture2D
{
public:
    unsigned int ID;
    GLenum activeTextureIndex;

    Texture2D(const char *texturePath, GLenum activeTexture, GLenum imageFormat)
    {
        activeTextureIndex = activeTexture;
        glGenTextures(1, &ID);
        glBindTexture(GL_TEXTURE_2D, ID);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        int width, height, nrChannels;
        unsigned char *data = stbi_load(texturePath, &width, &height, &nrChannels, 0);
        if (data)
        {
            glTexImage2D(GL_TEXTURE_2D, 0, imageFormat, width, height, 0, imageFormat, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);
        }
        else
        {
            std::cout << "Failed to load texture " << texturePath << std::endl;
        }

        stbi_image_free(data);
    }

    /// @brief Activates the texture using its activeTextureIndex, ie. GL_TEXTURE0.
    void use()
    {
        glActiveTexture(activeTextureIndex);
    }

    /// @brief Activates and binds the texture to GL_TEXTURE_2D.
    void bind() {
        use();
        glBindTexture(GL_TEXTURE_2D, ID);
    }
};

#endif