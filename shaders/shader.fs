#version 330 core

// Define the type and name of the data being passed to the fragment shader.
in vec3 ourColor;

// Define the type and name of the data the fragment shader passes back to the caller.
out vec4 FragColor;

void main()
{
    FragColor = vec4(ourColor, 1.0f);
}

