# Tworzysz swoją bibliotekę
add_library(slk_raylib_basics STATIC src/basics.cpp include/basics.hpp)

# Łączysz swoją bibliotekę z raylib
# Używamy PUBLIC, jeśli w Twoich plikach .h używasz typów z raylib (np. Rectangle, Color)
# Używamy PRIVATE, jeśli raylib jest używany tylko wewnątrz plików .cpp
target_link_libraries(slk_raylib_basics PUBLIC raylib)

# Upewnij się, że Twoja biblioteka wie, gdzie szukać własnych nagłówków
target_include_directories(slk_raylib_basics PUBLIC include)