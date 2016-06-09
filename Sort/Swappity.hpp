#pragma once

template <typename Type> void swappity(Type& orig, Type& dest, Type& slot)
{
	Type tmp = slot;
	slot     = dest;
	dest     = orig;
	orig     = tmp;
}

template <typename Type> void swappity(Type* orig, Type* dest, Type* slot)
{
	Type tmp = *slot;
	*slot    = *dest;
	*dest    = *orig;
	*orig    = tmp;
}