local common = import "common.jsonnet";

function(params) {
  components: {
    PlatformRendering: {},
    Transform: {},
    PhysicsBody: common.getPos(params) + {
      body: "platform body.json",
      [if "size" in params then "scale"]: params.size
    }
  }
}
