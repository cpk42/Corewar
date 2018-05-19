dotcors=()
opts=()
while test $# -gt 0; do
	if [[ $1 == -d || $1 == -s || $1 == -v ]]; then
		opts+=("$1")
		shift
		opts+=("$1")
		shift
	elif [[ $1 == -* ]]; then
		opts+=("$1")
		shift
	else
		base=`basename -s .cor $1`
		base=`basename -s .s $base`
		if [ ! -f $base.cor ]; then
			~/asm $base.s
		fi
		if [ ! -f $base.cor ]; then
			exit 1
		else
			dotcors+=("$base".cor)
		fi
		shift
	fi
done
~/corewar "${opts[@]}" "${dotcors[@]}"
