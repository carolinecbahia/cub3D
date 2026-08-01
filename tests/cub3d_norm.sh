#!/bin/bash
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    cub3d_norm.sh                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/30 00:00:00 by ccavalca          #+#    #+#              #
#    Updated: 2026/01/30 00:00:00 by ccavalca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Check if norminette is installed (multiple possible locations)
NORM_CMD=""

# Try virtualenv first
if [ -f "$HOME/42cursus/.venv/bin/norminette" ]; then
    NORM_CMD="$HOME/42cursus/.venv/bin/norminette"
# Try global command
elif command -v norminette &> /dev/null; then
    NORM_CMD="norminette"
# Try python module
elif python3 -m norminette --version &> /dev/null 2>&1; then
    NORM_CMD="python3 -m norminette"
fi

# If not found, show error
if [ -z "$NORM_CMD" ]; then
    echo "Error: norminette is not installed!"
    echo "Install with: pip3 install norminette"
    exit 1
fi

# Directories to check
CUB3D_ROOT="$(dirname $(dirname $(realpath "$0")))"
OUTPUT_FILE="$CUB3D_ROOT/tests/norminette_report_$(date +%Y%m%d_%H%M%S).txt"

mkdir -p "$CUB3D_ROOT/templates/cub3D analysis"

echo "========================================" | tee "$OUTPUT_FILE"
echo "  NORMINETTE REPORT - CUB3D" | tee -a "$OUTPUT_FILE"
echo "  $(date '+%Y-%m-%d %H:%M:%S')" | tee -a "$OUTPUT_FILE"
echo "========================================" | tee -a "$OUTPUT_FILE"
echo "" | tee -a "$OUTPUT_FILE"

# Check libft
if [ -d "$CUB3D_ROOT/libft" ]; then
    echo "==> Checking libft..." | tee -a "$OUTPUT_FILE"
    echo "----------------------------------------" | tee -a "$OUTPUT_FILE"
    $NORM_CMD "$CUB3D_ROOT/libft" 2>&1 | tee -a "$OUTPUT_FILE"
    echo "" | tee -a "$OUTPUT_FILE"
fi

# Check includes
if [ -d "$CUB3D_ROOT/inc" ]; then
    echo "==> Checking inc/..." | tee -a "$OUTPUT_FILE"
    echo "----------------------------------------" | tee -a "$OUTPUT_FILE"
    $NORM_CMD "$CUB3D_ROOT/inc" 2>&1 | tee -a "$OUTPUT_FILE"
    echo "" | tee -a "$OUTPUT_FILE"
fi
if [ -d "$CUB3D_ROOT/inc_bonus" ]; then
    echo "==> Checking inc_bonus/..." | tee -a "$OUTPUT_FILE"
    echo "----------------------------------------" | tee -a "$OUTPUT_FILE"
    $NORM_CMD "$CUB3D_ROOT/inc_bonus" 2>&1 | tee -a "$OUTPUT_FILE"
    echo "" | tee -a "$OUTPUT_FILE"
fi

# Check src
if [ -d "$CUB3D_ROOT/src" ]; then
    echo "==> Checking src/..." | tee -a "$OUTPUT_FILE"
    echo "----------------------------------------" | tee -a "$OUTPUT_FILE"
    $NORM_CMD "$CUB3D_ROOT/src" 2>&1 | tee -a "$OUTPUT_FILE"
    echo "" | tee -a "$OUTPUT_FILE"
fi
if [ -d "$CUB3D_ROOT/src_bonus" ]; then
    echo "==> Checking src_bonus/..." | tee -a "$OUTPUT_FILE"
    echo "----------------------------------------" | tee -a "$OUTPUT_FILE"
    $NORM_CMD "$CUB3D_ROOT/src_bonus" 2>&1 | tee -a "$OUTPUT_FILE"
    echo "" | tee -a "$OUTPUT_FILE"
fi

# Summary
echo "========================================" | tee -a "$OUTPUT_FILE"
echo "  SUMMARY" | tee -a "$OUTPUT_FILE"
echo "========================================" | tee -a "$OUTPUT_FILE"

# Count errors
ERROR_COUNT=$(grep -c "Error" "$OUTPUT_FILE" || echo "0")
OK_COUNT=$(grep -c "OK!" "$OUTPUT_FILE" || echo "0")

echo "Files OK: $OK_COUNT" | tee -a "$OUTPUT_FILE"
echo "Errors found: $ERROR_COUNT" | tee -a "$OUTPUT_FILE"
echo "" | tee -a "$OUTPUT_FILE"
echo "Report saved to: $OUTPUT_FILE" | tee -a "$OUTPUT_FILE"

# Return appropriate exit code
if [ "$ERROR_COUNT" -gt 0 ]; then
    exit 1
else
    exit 0
fi
