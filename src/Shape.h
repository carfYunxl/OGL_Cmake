#ifndef SHAPE_H_
#define SHAPE_H_

#include "VertexArray.h"
#include "Shader.h"
#include <vector>
#include <memory>
#include "Camera.h"

namespace GL
{
    struct VertexBuffer;
    struct IndexBuffer;
    // struct Texture;

    class Triangle
    {
    public:
        explicit Triangle(const char* imagepath);
        ~Triangle();

        void Draw();
    private:
        VertexArray                     m_vertexArray;
        std::unique_ptr<VertexBuffer>   m_vertexBuffer;
        std::unique_ptr<IndexBuffer>    m_indexBuffer;
        // std::unique_ptr<Texture>        m_Texture;

        std::vector<float>          m_Vertices{
                0.0f,  0.0f, 0.0f, 0.0f, 0.0f,
                0.5f,  0.0f, 0.0f, 1.0f, 0.0f,
                0.25f, 0.5f, 0.0f, 0.5f, 1.0f
                };
        std::vector<unsigned int>   m_Indices{
              0,1,2
        };
    };

    class Rectangle
    {
    public:
        explicit Rectangle(const char* imagepath);
        ~Rectangle();

        void Draw();
    private:
        VertexArray                     m_vertexArray;
        std::unique_ptr<VertexBuffer>   m_vertexBuffer;
        std::unique_ptr<IndexBuffer>    m_indexBuffer;
        // std::unique_ptr<Texture>        m_Texture;

        std::vector<float>              m_Vertices{
        // positions        // texture coords
         0.0f,  0.0f, 0.0f,   1.0f, 1.0f, // top right
         0.0f, -0.5f, 0.0f,   1.0f, 0.0f, // bottom right
        -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, // bottom left
        -0.5f,  0.0f, 0.0f,   0.0f, 1.0f  // top left 
        };
        std::vector<unsigned int>   m_Indices{
              0,1,3,
              1,2,3
        };
    };

    class Cube
    {
    public:
        Cube(Shader& shader);
        ~Cube();

        void Draw(const Camera& camera, const glm::vec3& pos, const glm::vec3& rotation, const glm::vec3& scale, uint32_t& draw_mode);
    private:
        VertexArray                     m_vertexArray;
        std::unique_ptr<VertexBuffer>   m_vertexBuffer;
        Shader&                         m_Shader;

        std::vector<float>              m_Vertices{
        // position           // texture  // normal        
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f, 0.0f,  0.0f, -1.0f,
         0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 0.0f,  0.0f, -1.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 0.0f,  0.0f, -1.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 0.0f,  0.0f, -1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 0.0f,  0.0f, -1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f, 0.0f,  0.0f, -1.0f,

        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 0.0f,  0.0f,  1.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 0.0f,  0.0f,  1.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 0.0f,  0.0f,  1.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 0.0f,  0.0f,  1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 1.0f, 0.0f,  0.0f,  1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 0.0f,  0.0f,  1.0f,

        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,-1.0f,  0.0f,  0.0f,
        -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,-1.0f,  0.0f,  0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,-1.0f,  0.0f,  0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,-1.0f,  0.0f,  0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,-1.0f,  0.0f,  0.0f,
        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,-1.0f,  0.0f,  0.0f,

         0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 1.0f,  0.0f,  0.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 1.0f,  0.0f,  0.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 1.0f,  0.0f,  0.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 1.0f,  0.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 1.0f,  0.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 1.0f,  0.0f,  0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f, -1.0f,  0.0f,
         0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 0.0f, -1.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 0.0f, -1.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 0.0f, -1.0f,  0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 0.0f, -1.0f,  0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f, -1.0f,  0.0f,
        
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 0.0f,  1.0f,  0.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 0.0f,  1.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f,  1.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 0.0f,  1.0f,  0.0f
        };
    };
}

#endif //SHAPE_H_