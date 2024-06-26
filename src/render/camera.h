#pragma once

#include <memory>

#include "libs.h"
#include "src/utils/key-manager.h"
#include "src/utils/stopwatch.h"

class Camera {
    struct GLFWwindow *window = nullptr;

    float aspectRatio = 4.0f / 3.0f;
    float fieldOfView = 80.0f;
    float zNear = 0.1f;
    float zFar = 500.0f;

    glm::vec3 pos = {0, 0, -15};
    glm::vec2 rot = {0.01f, 0.01f}; // not {0, 0} to try to hide the horizontal line hole in rendering
    glm::vec3 front{}, right{}, up{};

    float rotationSpeed = 2.5f;
    float movementSpeed = 8.0f;
    bool isCursorLocked = true;

    /**
     * Auto mode automatically moves the camera around the world origin while maintaining the eye direction
     * so that it looks directly at the origin.
     */
    bool isInAutoMode = false;
    float autoModeSpeed = 1.0f;
    float autoModeRadius = 20.0f;
    float autoModeAngleY = 0.0f;
    Stopwatch autoModeStopwatch;

    std::unique_ptr<KeyManager> keyManager;

public:
    explicit Camera(GLFWwindow *w);

    void tick(float deltaTime);

    [[nodiscard]]
    glm::vec3 getPos() const { return pos; }

    [[nodiscard]]
    glm::mat4 getViewMatrix() const;

    [[nodiscard]]
    glm::mat4 getStaticViewMatrix() const;

    [[nodiscard]]
    glm::mat4 getProjectionMatrix() const;

    void updateRotation(float dx = 0.0f, float dy = 0.0f);

    /**
     * Locks or unlocks the cursor. When the cursor is locked, it's confined to the center
     * of the screen and camera rotates according to its movement. When it's unlocked, it's
     * visible and free to move around the screen; most importantly able to use the GUI.
     */
    void setIsCursorLocked(bool b);

    void renderGuiSection();

private:
    /**
     * Binds keys used to rotate the camera.
     */
    void bindRotationKeys();

    /**
     * Binds keys used to move the camera.
     */
    void bindMovementKeys();

    /**
     * When in locked cursor mode, rotates the camera according to the mouse's movement and centers it.
     */
    void tickMouseMovement(float deltaTime);

    /**
     * Updates the aspect ratio to reflect the current window's dimensions.
     */
    void updateAspectRatio();

    /**
     * Updates the `front`, `right` and `up` vectors, which are used to help determine
     * what is visible to the camera.
     */
    void updateVecs();

    /**
     * Ticks the camera's state when in auto mode.
     */
    void tickAutoMode();

    /**
     * Moves the cursor to the center of the window.
     */
    void centerCursor() const;
};
