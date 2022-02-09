cmake_minimum_required(VERSION 3.5)
project(dna_profiler VERSION 0.1 LANGUAGES CXX )


include_directories( include )

add_executable( dna_profiler
                src/Main.cpp
                src/UserInterface.cpp
                src/DNAProfile.cpp
                src/Database.cpp
)