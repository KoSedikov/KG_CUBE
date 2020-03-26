#include <GL/glew.h>
#include<GL/glut.h>
#include <GLFW/glfw3.h> // GLFW helper library
#include <stdio.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.inl>

using glm::vec3;
using glm::vec4;
using glm::rotate;

int main()
{



	// start GL context and O/S window using the GLFW helper library
	if (!glfwInit()) {
		fprintf(stderr, "ERROR: could not start GLFW3\n");
		return 1;
	}

	// uncomment these lines if on Apple OS X
	/*glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);*/

	GLFWwindow* window = glfwCreateWindow(640, 480, "Hello Triangle", NULL, NULL);
	if (!window) {
		fprintf(stderr, "ERROR: could not open window with GLFW3\n");
		glfwTerminate();
		return 1;
	}
	glfwMakeContextCurrent(window);

	// start GLEW extension handler
	glewExperimental = GL_TRUE;
	glewInit();

	// get version info
	const GLubyte* renderer = glGetString(GL_RENDERER); // get renderer string
	const GLubyte* version = glGetString(GL_VERSION); // version as a string
	printf("Renderer: %s\n", renderer);
	printf("OpenGL version supported %s\n", version);

	/* tell GL to only draw onto a pixel if the shape is closer to the viewer
		glEnable(GL_DEPTH_TEST); // enable depth-testing
		glDepthFunc(GL_LESS); // depth-testing interprets a smaller value as "closer"

		/* OTHER STUFF GOES HERE NEXT */

		// close GL context and any other GLFW resources
		//glfwTerminate();

	float points[] = {
   -0.5f,-0.5f,-0.5f, // Треугольник 1 : начало
	-0.5f,-0.5f, 0.5f,
	-0.5f, 0.5f, 0.5f, // Треугольник 1 : конец
	 0.5f, 0.5f,-0.5f, // Треугольник 2 : начало
	-0.5f,-0.5f,-0.5f,
	-0.5f, 0.5f,-0.5f, // Треугольник 2 : конец
	0.5f,-0.5f, 0.5f,
	-0.5f,-0.5f,-0.5f,
	0.5,-0.5f,-0.5f,
	0.5f, 0.5f,-0.5f,
	0.5f,-0.5f,-0.5f,
	-0.5f,-0.5f,-0.5f,
	-0.5f,-0.5f,-0.5f,
	-0.5f, 0.5f, 0.5f,
	-0.5f, 0.5f,-0.5f,
	 0.5f,-0.5f, 0.5f,
	-0.5f,-0.5f, 0.5f,
	-0.5f,-0.5f,-0.5f,
	-0.5f, 0.5f, 0.5f,
	-0.5f,-0.5f, 0.5f,
	0.5f,-0.5f, 0.5f,
	0.5f, 0.5f, 0.5f,
	0.5f,-0.5f,-0.5f,
	0.5f, 0.5f,-0.5f,
	0.5f,-0.5f,-0.5f,
	0.5f, 0.5f, 0.5f,
	0.5f,-0.5f, 0.5f,
	0.5f, 0.5f, 0.5f,
	0.5f, 0.5f,-0.5f,
	-0.5f, 0.5f,-0.5f,
	0.5f, 0.5f, 0.5f,
	-0.5f, 0.5f,-0.5f,
	-0.5f, 0.5f, 0.5f,
	0.5f, 0.5f, 0.5f,
	-0.5f, 0.5f, 0.5f,
	0.5f,-0.5f, 0.5f
	};
	float colors[] = {
   0.583f,  0.771f,  0.014f,
	0.609f,  0.115f,  0.436f,
	0.327f,  0.483f,  0.844f,
	0.822f,  0.569f,  0.201f,
	0.435f,  0.602f,  0.223f,
	0.310f,  0.747f,  0.185f,
	0.597f,  0.770f,  0.761f,
	0.559f,  0.436f,  0.730f,
	0.359f,  0.583f,  0.152f,
	0.483f,  0.596f,  0.789f,
	0.559f,  0.861f,  0.639f,
	0.195f,  0.548f,  0.859f,
	0.014f,  0.184f,  0.576f,
	0.771f,  0.328f,  0.970f,
	0.406f,  0.615f,  0.116f,
	0.676f,  0.977f,  0.133f,
	0.971f,  0.572f,  0.833f,
	0.140f,  0.616f,  0.489f,
	0.997f,  0.513f,  0.064f,
	0.945f,  0.719f,  0.592f,
	0.543f,  0.021f,  0.978f,
	0.279f,  0.317f,  0.505f,
	0.167f,  0.620f,  0.077f,
	0.347f,  0.857f,  0.137f,
	0.055f,  0.953f,  0.042f,
	0.714f,  0.505f,  0.345f,
	0.783f,  0.290f,  0.734f,
	0.722f,  0.645f,  0.174f,
	0.302f,  0.455f,  0.848f,
	0.225f,  0.587f,  0.040f,
	0.517f,  0.713f,  0.338f,
	0.053f,  0.959f,  0.120f,
	0.393f,  0.621f,  0.362f,
	0.673f,  0.211f,  0.457f,
	0.820f,  0.883f,  0.371f,
	0.982f,  0.099f,  0.879f
	};
	/////////////////////////////////////////////////////////
	GLuint vbo[2];
	glGenBuffers(2, vbo);
	GLuint points_vbo = vbo[0];
	GLuint colours_vbo = vbo[1];
	//



	glBindBuffer(GL_ARRAY_BUFFER, points_vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, colours_vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);
	////////////////////////////////////////////////////////////////////////////////
	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);


	glBindBuffer(GL_ARRAY_BUFFER, points_vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glEnableVertexAttribArray(0);
	//////////////////////////////////////////////////////////////////////////////////
	glBindBuffer(GL_ARRAY_BUFFER, colours_vbo);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glEnableVertexAttribArray(1);
	/////////////////////////////////////////////////////////////////////////////////////////////

	const char* vertex_shader =
		"#version 400\n"

		"layout(location = 0) in vec3 vertex_position;"
		"layout(location = 1) in vec3 vertex_colour;"
		"uniform mat4 model;"
		"out vec3 color;"

		"void main() {"
		"color = vertex_colour;"
		"gl_Position = model*vec4(vertex_position, 1.0); "

		"}";
	const char* fragment_shader =
		"#version 400\n"
		"in vec3 color;"
		"layout(location = 0) out vec4 fragcolor;"
		"void main() {"
		"  fragcolor = vec4(color, 1.0);"
		"}";
	GLuint vs = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vs, 1, &vertex_shader, NULL);
	glCompileShader(vs);
	GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fs, 1, &fragment_shader, NULL);
	glCompileShader(fs);

	GLuint shader_programme = glCreateProgram();
	glAttachShader(shader_programme, fs);
	glAttachShader(shader_programme, vs);

	glBindAttribLocation(shader_programme, 0, "vertex_position");
	glBindAttribLocation(shader_programme, 1, "vertex_colour");

	glLinkProgram(shader_programme);
	while (!glfwWindowShouldClose(window)) {
		// wipe the drawing surface clear

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		glm::mat4 model(1.0f);
		model = glm::translate(model, vec3(0.2f, 0.0f, 0.0f));
		model = glm::rotate(model, 60.0f, vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, 15.0f, vec3(1.0f, 1.0f, 0.0f));
		
		model = glm::scale(model, vec3(1.0f));

		GLuint location = glGetUniformLocation(shader_programme, "model");
			if(location>=0)
			{
				glUniformMatrix4fv(location, 1, GL_FALSE, &model[0][0]);
			}
	
		glUseProgram(shader_programme);
		glBindVertexArray(vao);
		glEnable(GL_DEPTH_TEST);
		// draw points 0-3 from the currently bound VAO with current in-use shader
		glDrawArrays(GL_TRIANGLES, 0, 36);
		// update other events like input handling 
		glfwPollEvents();
		// put the stuff we've been drawing onto the display
		glfwSwapBuffers(window);
	}

	return 0;
}
