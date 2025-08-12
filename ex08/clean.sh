#!/bin/sh
find . -type f \( -name '*~' -or -name '#*#' \) | xargs rm
