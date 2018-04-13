import json
import subprocess

def hypot(config, prefix = '/tmp'):
    with open(prefix + '/config.json', 'w') as f:
        json.dump(config, f)

    subprocess.run(["./hypot", prefix])\
        .check_returncode()

    with open(prefix + '/result.json', 'r') as f:
        result = json.load(f)

    return result
