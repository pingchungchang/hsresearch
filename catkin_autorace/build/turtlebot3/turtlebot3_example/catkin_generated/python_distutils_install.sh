#!/bin/sh

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/pcc/catkin_autorace/src/turtlebot3/turtlebot3_example"

# ensure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/pcc/catkin_autorace/install/lib/python2.7/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/pcc/catkin_autorace/install/lib/python2.7/dist-packages:/home/pcc/catkin_autorace/build/lib/python2.7/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/pcc/catkin_autorace/build" \
    "/usr/bin/python2" \
    "/home/pcc/catkin_autorace/src/turtlebot3/turtlebot3_example/setup.py" \
     \
    build --build-base "/home/pcc/catkin_autorace/build/turtlebot3/turtlebot3_example" \
    install \
    --root="${DESTDIR-/}" \
    --install-layout=deb --prefix="/home/pcc/catkin_autorace/install" --install-scripts="/home/pcc/catkin_autorace/install/bin"
