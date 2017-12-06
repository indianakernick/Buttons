local common = import "common.jsonnet";

function(params) {
  components: {
    Activation: {
      speed: 4
    },
    Door: {},
    DoorRendering: {},
    Transform: {},
    PhysicsBody: {
      [if "pos" in params then "pos"]: common.getOrientPos(params),
      [if "size" in params then "scale"]: params.size,
      rotation: common.getOrientAngle(params),
      body: "door body.json"
    },
    PowerInput: common.getPowerInput(params)
  }
}
