all:
		@make -j4 -C lapin || make re -C lapin
		@make -j4 -C sfml || make re -C sfml
		@make -j4 -C ncurses || make re -C ncurses

fclean:
		@make fclean -C lapin
		@make fclean -C sfml
		@make fclean -C ncurses
		@rm -rf ../lib
