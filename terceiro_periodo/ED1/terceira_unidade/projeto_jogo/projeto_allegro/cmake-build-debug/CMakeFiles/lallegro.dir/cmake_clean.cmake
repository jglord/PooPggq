file(REMOVE_RECURSE
  "liblallegro.pdb"
  "liblallegro.so"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/lallegro.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
