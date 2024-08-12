#! /bin/bash
usage() {
    echo "usage: source run.sh"
}

if [[ "${BASH_SOURCE[0]}" == "${0}" ]]; then
    usage
    exit 1
fi

# want to explicitly set the path therefore, "source" ./run.sh is needed
export PATH="$HOME/opt/cross/bin:$PATH"
