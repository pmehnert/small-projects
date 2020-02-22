#include "renderer.hpp"

#include "../shaders.hpp"
#include "../util.hpp"


using namespace conway;

Renderer::Renderer()
{
    GLuint vertex_shader, fragment_shader;
    if (!LoadShader(&vertex_shader, GL_VERTEX_SHADER, shaders::ConwayVertexSource.c_str(),
                    shaders::ConwayVertexSource.size())) {
        exit(EXIT_FAILURE);
    }
    if (!LoadShader(&fragment_shader, GL_FRAGMENT_SHADER, shaders::ConwayFragmentSource.c_str(),
                    shaders::ConwayFragmentSource.size())) {
        exit(EXIT_FAILURE);
    }

    shader_program_ = glCreateProgram();
    glAttachShader(shader_program_, vertex_shader);
    glAttachShader(shader_program_, fragment_shader);
    if (!LinkProgram(shader_program_)) {
        exit(EXIT_FAILURE);
    }

    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);

    glUseProgram(shader_program_);
    glUniform1i(glGetUniformLocation(shader_program_, "grid"), 0);
}

void Renderer::draw(GLuint vertex_array, GLuint texture)
{
    glUseProgram(shader_program_);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);
    glBindVertexArray(vertex_array);
    glDrawArrays(GL_TRIANGLES, 0, 6);
}