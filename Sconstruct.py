env = Environment()
env.Append(LIBS = ['sfml-graphics','sfml-system'])
main = env.Program(target='main', source=['src/main.cc'])
Default(main)
