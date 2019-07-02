find . -type f -name "*.sh" | sed "s/.*\///g" | sed "s/\.sh//g"
