local common = import "common.jsonnet";

function(params) {
  components: common.checkParams(params, ["pos", "size"]) {
    StaticSpriteRendering: {
      sprite: "box",
      depth: common.getDepth("box")
    },
    Transform: {},
    PhysicsBody: common.getPosSize(params) + {
      body: (import "box body.json")
    }
  }
}
