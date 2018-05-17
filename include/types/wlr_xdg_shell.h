#ifndef TYPES_WLR_XDG_SHELL_H
#define TYPES_WLR_XDG_SHELL_H

#include <wayland-server.h>
#include <wlr/types/wlr_xdg_shell.h>
#include "xdg-shell-protocol.h"

struct wlr_xdg_positioner_resource {
	struct wl_resource *resource;
	struct wlr_xdg_positioner attrs;
};

#define XDG_TOPLEVEL_ROLE "xdg_toplevel"
#define XDG_POPUP_ROLE "xdg_popup"

uint32_t schedule_xdg_surface_configure(struct wlr_xdg_surface *surface);
struct wlr_xdg_surface *create_xdg_surface(
	struct wlr_xdg_client *client, struct wlr_surface *surface,
	uint32_t id);
void unmap_xdg_surface(struct wlr_xdg_surface *surface);
void destroy_xdg_surface(struct wlr_xdg_surface *surface);

void create_xdg_positioner(struct wlr_xdg_client *client, uint32_t id);
struct wlr_xdg_positioner_resource *get_xdg_positioner_from_resource(
	struct wl_resource *resource);

void create_xdg_popup(struct wlr_xdg_surface *xdg_surface,
	struct wlr_xdg_surface *parent,
	struct wlr_xdg_positioner_resource *positioner, int32_t id);
void handle_xdg_surface_popup_committed(struct wlr_xdg_surface *surface);
struct wlr_xdg_popup_grab *get_xdg_shell_popup_grab_from_seat(
	struct wlr_xdg_shell *shell, struct wlr_seat *seat);
void destroy_xdg_popup(struct wlr_xdg_surface *surface);

void create_xdg_toplevel(struct wlr_xdg_surface *xdg_surface,
	uint32_t id);
void handle_xdg_surface_toplevel_committed(struct wlr_xdg_surface *surface);
void send_xdg_toplevel_configure(struct wlr_xdg_surface *surface,
	struct wlr_xdg_surface_configure *configure);
void handle_xdg_toplevel_ack_configure(struct wlr_xdg_surface *surface,
	struct wlr_xdg_surface_configure *configure);
bool compare_xdg_surface_toplevel_state(struct wlr_xdg_toplevel *state);
void destroy_xdg_toplevel(struct wlr_xdg_surface *surface);

#endif
