import configparser
import subprocess


def readProps(prefsLoc):
    """Read the version of our project as a string"""

    config = configparser.RawConfigParser()
    config.read(prefsLoc)
    version = dict(config.items("VERSION"))
    verObj = dict(
        short=f"{version["major"]}.{version["minor"]}.{version["build"]}",
        long="unset",
        rpm="unset",  # https://docs.fedoraproject.org/en-US/packaging-guidelines/Versioning/
    )

    # Try to find current build SHA if if the workspace is clean.  This could fail if git is not installed
    try:
        sha = (
            subprocess.check_output(["git", "rev-parse", "--short", "HEAD"])
            .decode("utf-8")
            .strip()
        )
        isDirty = (
            subprocess.check_output(["git", "diff", "HEAD"]).decode("utf-8").strip()
        )
        suffix = sha
        # if isDirty:
        #     # short for 'dirty', we want to keep our verstrings source for protobuf reasons
        #     suffix = sha + "-d"
        verObj["long"] = f"{verObj["short"]}.{suffix}"
        verObj["rpm"] = f"{verObj["short"]}^1.git{sha}"
    except:
        # print("Unexpected error:", sys.exc_info()[0])
        # traceback.print_exc()
        verObj["long"] = verObj["short"]
        verObj["rpm"] = verObj["short"]

    # print("firmware version " + verStr)
    return verObj


# print("path is" + ','.join(sys.path))
