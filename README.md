The Crew: The Quest for Planet Nine (C Version)

This project was coded by myself and two other students over a few weeks during the spring of 2024 as an assignment for coding class at ESTACA.

About The Crew: The Quest for Planet Nine
The Crew is a trick-taking cooperative card game for 2–5 players designed by Thomas Sing and released in 2019.
The Crew is played across 50 'missions' where players aim to win tricks based on their task cards, but can only communicate limited information while doing so.
Upon its release, The Crew received critical success and won numerous awards. A sequel, The Crew: Mission Deep Sea, was released in 2021.

In our version coded in C, all missions are generated randomly.


How to Execute the Card Game : 
With Code::Blocks

    Download the project files and open the .cbp file using the Code::Blocks IDE (this IDE was mandatory as part of the assignment).

    Build and run the code within Code::Blocks.

Without Code::Blocks

    Download the project files.

    Make sure you have a C compiler installed (e.g., GCC or Clang).

    Open a terminal or command prompt.

    Navigate to the folder containing the source files.

    Compile the program manually, for example:

    gcc -o the_crew main.c other_source_files.c

    Replace main.c and other_source_files.c with the actual filenames.

Project Structure

    main.c — Entry point of the program.

    Other .c and .h files — Contain the game logic, card handling, missions, and player interactions.

    .cbp file — Code::Blocks project file (optional outside Code::Blocks).

Notes

    The program runs in the console/terminal.

    This version is a simplified digital adaptation; some features of the physical game may be missing or altered.

    Random mission generation means the gameplay experience will differ every time.

License

MIT License
